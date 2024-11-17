#include <iostream>
using namespace std;

class B
{
private:
    int m_b;

public:
    B(const int &m_b_in)
        : m_b(m_b_in)
    {
    }
};

class Something
{
    // 변수 선언보다 생성자가 더 우선순위가 높다.
    // 개인적인 생각엔 변수 선언해서 값이 들어간 곳에 생성자들의 값이 다시 들어간 것이 아닌가 싶음.
    // 우선순위라기보단 실행 순서가 변수선언이 생성자보다 뒤인듯. 왜냐하면 다른 클래스가 있는지 탐색해야 하기 때문 아닐까 싶음.
    // 멤버 선언을 받아야 생성자에서 값을 넣던 말던 형식에 맞춰서 실행할테니
private:
    int m_i = 100;
    double m_d = 100.0;
    char m_c = 'F';
    int m_arr[5] = {100, 200, 300, 400, 500};
    B m_b{1024};

public:
    Something()
        : m_i{1}, m_d{3.14}, m_c{'a'}, m_arr{1, 2, 3, 4, 5}, m_b(m_i - 1)
    {
        m_i *= 3;
        m_d *= 3.0;
        m_c += 3;
    }

    void print()
    {
        cout << m_i << " " << m_d << " " << m_c << endl;
        for (auto e : m_arr)
            cout << e << " ";
        cout << endl;
    }
};

int main()
{
    Something some;
    some.print();

    return 0;
}