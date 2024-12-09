#include <iostream>

using namespace std;
class Digit
{
  private:
    int m_digit;

  public:
    Digit(int digit = 0) : m_digit(digit)
    {
    }

    // prefix
    Digit &operator++()
    {
        ++m_digit;

        return *this;
    }

    // postfix 일 경우 파라미터에 더미가 들어감 ( 증감 되는 자료형 적어주면 될 듯 ?++)
    Digit operator++(int)
    {
        Digit temp(m_digit);

        ++(*this);

        return temp;
        // 현재값을 저장하고 리턴하는 이유는 그 실행 과정엔 값이 늘어나면 안되기 때문에. 현재값을 리턴해주고 값을
        // 증가시켜준 뒤 , 저장된 값을 리턴해줌
    }

    friend ostream &operator<<(ostream &out, const Digit &d)
    {
        out << d.m_digit;
        return out;
    }
};

int main()
{
    Digit d(5);

    cout << ++d << endl;
    cout << d << endl;

    cout << d++ << endl;
    cout << d << endl;

    // 증감연산자에 대해
    // ++ int a = > a 값을 먼저 +1 하고 실행
    // int a ++ = > 실행 후 a 값을 +1

    return 0;
}