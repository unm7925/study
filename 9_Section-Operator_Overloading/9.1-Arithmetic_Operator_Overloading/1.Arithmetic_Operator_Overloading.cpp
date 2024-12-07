#include <iostream>

using namespace std;

class Cents
{
  private:
    int m_cents;

  public:
    Cents(int cents = 0)
    {
        m_cents = cents;
    }
    int getCents() const
    {
        return m_cents;
    }

    int &getCents()
    {
        return m_cents;
    }

    // 내부 변수에 직접 영향을 주고 받기 위해 getCents() 가 아닌 그 멤버변수 m_cents로 직접 영향을 줌
    /*
    friend Cents operator+(const Cents &c1, const Cents &c2)
    {
        return Cents(c1.m_cents + c2.m_cents);
    }
    */
    // 멤버로 한다면 대부분 좌측에 있는걸 this로 사용 { = , [인덱스], (파라미터), -> } 중괄호 안에 있는 것들은
    // 멤버펑션으로만 가능
    Cents operator+(const Cents &c2)
    {
        return Cents(this->m_cents + c2.m_cents);
    }
};

// 더하고 싶을 경우
/*
    1. 산술연산자 없이 인자 3개로 받아 올 경우
        void add(const Cents &c1, const Cents &2, Cents &c_out) { c_out.getCents() = c1.getCents() + c2.getCents()}
    2. 산술연산자 없이 인자 2개로 리턴 받을 경우
        Cents add(const Cents &c1, const Cents &c2) { return Cents(c1.getCents()+ c2.getCents());}
    3. 산술연산자로 인자 2개를 통해 리턴 받을 경우
        - 아래와 같음
*/

/* getCents() 를 통해 내부 멤버 변수에 영향
    Cents operator+(const Cents &c1, const Cents &c2)
    {
        return Cents(c1.getCents() + c2.getCents());
    }
*/

int main()
{
    Cents cents1(6);
    Cents cents2(8);

    /* 1. void add 함수에 3번째 인자로 값을 받을경우
    Cents sum;
        add(cents1, cents2, sum);
    */

    /* 2. Cents add 함수로 리턴값을 바로 받아서 사용 할 경우
    cout << add(cents1,cents2).getCents() << endl;
    */

    /*  3. 산술연산자를 사용하여 받아 올 경우 ( 수학공부를 할 때 새로운 기호 연산자를 만들어 문제 내는 유형과 흡사함 )
        안되는 것 { ?: , :: 스코프연산자, sizeof , .멤버 , .*멤버주소}
     cout << (cents1 + cents2).getCents() << endl;
    */
    return 0;
}