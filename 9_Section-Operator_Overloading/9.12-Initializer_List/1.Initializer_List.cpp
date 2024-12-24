#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
    unsigned int m_length = 0;
    int *m_data = nullptr;

public:
    IntArray(unsigned length)
        : m_length(length)
    {
        m_data = new int[length];
    }

    IntArray(const std::initializer_list<int> &list)
        : IntArray(list.size())
    {
        int count = 0;
        for (auto &element : list)
        {
            m_data[count] = element;
            ++count;
        }
        /*
        for (unsigned count = 0; count < list.size(); ++count)
            m_data[count] = list[count]; // list는 [] 첨자를 제공 x
        */
    }

    ~IntArray()
    {
        delete[] this->m_data;
    }

    IntArray &operator=(const IntArray &source)
    {
        if (this == &source)
            return *this;

        delete[] m_data;

        m_length = source.m_length;

        if (source.m_data != nullptr)
        {
            m_data = new int[m_length];

            for (int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
    }

    friend ostream &operator<<(ostream &out, IntArray &arr)
    {
        for (unsigned i = 0; i < arr.m_length; ++i)
        {
            out << arr.m_data[i] << " ";
        }

        out << endl;

        return out;
    }
};

int main()
{
    int my_arr1[5] = {1, 2, 3, 4, 5};
    int *my_arr2 = new int[5]{1, 2, 3, 4, 5};

    auto il = {10, 20, 30};

    IntArray int_array{1, 2, 3, 4, 5};
    cout << int_array << endl;
    return 0;
}