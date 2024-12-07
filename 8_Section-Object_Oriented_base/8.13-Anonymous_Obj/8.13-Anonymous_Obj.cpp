#include <iostream>

using namespace std;

// if (1)
/*
class A
{
  public:
    int m_value;

    A(const int &input) : m_value(input)
    {
        cout << "Constructor" << endl;
    }
    ~A()
    {
        cout << "Destructor" << endl;
    }

    void print()
    {
        cout << m_value << endl;
    }
};
*/

class Cents
{
  private:
    int m_cents;

  public:
    Cents(int cents)
    {
        m_cents = cents;
    }

    int getCents() const
    {
        return m_cents;
    }
};

Cents add(const Cents &c1, const Cents &c2)
{
    return Cents(c1.getCents() + c2.getCents());
}

int main()
{
    // if(1)
    /*
    A a(1);
    a.print();
    a.print();

    A(1).print(); <- L 벨류가 아닌 R 벨류로 작동이되고, 일회성으로 생성 및 소멸이 된다.
    */

    cout << add(Cents(6), Cents(8)).getCents() << endl;

    cout << int(6) + int(8) << endl;

    return 0;
}