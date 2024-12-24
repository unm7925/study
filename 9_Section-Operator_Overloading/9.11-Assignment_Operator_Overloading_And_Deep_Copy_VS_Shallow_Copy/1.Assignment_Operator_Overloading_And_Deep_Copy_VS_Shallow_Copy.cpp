#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class Mystring
{
    // private:
public:
    char *m_data = nullptr;
    int m_length = 0;

public:
    // 임시로 얕은 복사 막는 법 delete 사용
    // Mystring(const Mystring &source) = delete;

    Mystring(const char *source = "")
    {
        assert(source);

        m_length = std::strlen(source) + 1;
        m_data = new char[m_length];

        for (int i = 0; i < m_length; ++i)
            m_data[i] = source[i];

        m_data[m_length - 1] = '\0';
    }

    Mystring(const Mystring &source)
    {
        // 주소를 새로 할당받고 모든 내용을 받아가면 깊은 복사
        cout << "Copy Constructor " << endl;

        m_length = source.m_length;

        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;
    }

    Mystring &operator=(const Mystring &source)
    {
        // shallow copy
        /*
        this->m_data = source.m_data;
        this->m_length = source.m_length;
        */

        cout << "assignment operator " << endl;

        if (this == &source) // prevent self-assignment
            return *this;    // 자신을 대입할 때는 못하게 막음

        delete[] m_data;

        m_length = source.m_length;

        if (source.m_data != nullptr)
        {
            m_data = new char[m_length];

            for (int i = 0; i < m_length; ++i)
                m_data[i] = source.m_data[i];
        }
        else
            m_data = nullptr;

        return *this;
    }

    ~Mystring()
    {
        delete[] m_data;
    }

    char *getString() { return m_data; }
    int getLength() { return m_length; }
};

int main()
{
    Mystring hello("Hello");

    Mystring str1 = hello; // 복사

    Mystring str2;

    str2 = hello; // 대입

    /*

    얕은 복사

    Mystring hello("Hello");

    cout << (int *)hello.m_data << endl;
    cout << hello.getString() << endl;

    {


        Mystring copy = hello; // 복사 생성자 호출
        // copy = hello => 대입연산자 호출

        cout << (int *)copy.m_data << endl;
        cout << copy.getString() << endl;
        // 주소값이 동일하게 되어 이 범위 밖으로 나가면
        // 소멸자로 인해 주소에 해당된 데이터값이 없어져버림.
        // 그래서 범위 밖 hello.getString()에 쓰레기값이 들어감
    }

    cout << hello.getString() << endl;
    */
    return 0;
}