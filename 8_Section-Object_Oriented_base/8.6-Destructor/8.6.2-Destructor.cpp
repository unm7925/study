#include <iostream>

using namespace std;

class IntArray
{
private:
    int *m_arr = nullptr; // vector
    int m_length = 0;

public:
    IntArray(const int length_in)
    {
        m_length = length_in;
        m_arr = new int[m_length];
    }
    ~IntArray()
    {
        if (m_arr != nullptr) // nullptr 일경우에 삭제를 하면 문제가 생김
            delete[] m_arr;   // vector 에 자동적으로 삭제기능 있음.
    }
    int size() { return m_length; }
};

int main()
{
    while (true)
    {
        IntArray my_int_arr(10000);
    }

    return 0;
}