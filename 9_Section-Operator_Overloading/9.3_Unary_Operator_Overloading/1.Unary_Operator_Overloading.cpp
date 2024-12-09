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
    Cents operator-() const
    {
        return Cents(-m_cents);
    }

    bool operator!() const
    {
        // !Cents(...) => 0 일경우 true , 그 외 false
        return (m_cents == 0) ? true : false; // 조건부 연산자
    }

    friend std::ostream &operator<<(std::ostream &out, const Cents &cents)
    {
        out << cents.m_cents;

        return out;
    }
};

int main()
{
    Cents cents1(6);
    Cents cents2(0);

    /* 단항연산자 임시 예시
    int a =3;

    cout << -a << endl;
    cout << !a << endl;
    */

    cout << cents1 << endl;
    cout << -cents2 << endl;
    cout << -Cents(-10) << endl;

    // 반환 타입 확인
    auto temp = !cents1;

    cout << !cents1 << " " << !cents2 << endl;

    return 0;
}