#include <iostream>

using namespace std;

class A;

class B
{
  private:
    int m_value = 2;

  public:
    void doSomething(A &a);
    // if(2)
    /*
    {
        cout << a.m_value << endl;
    }
    */
    // if(1)
    //  friend void doSomething(A &a, B &b);
};

// if(1,2)
// class B; // class A 가 B가 있는걸 인지시키기 위해 전방선언을 해줌

class A
{
  private:
    int m_value = 1;

    friend void B::doSomething(A &a);

    // if(1)
    // friend void doSomething(A &a, B &b);
    //  객체지향을 깨지않기 위해 private를 고치기보단 이런식으로 사용해서 접근가능한 상태로 만듦

    // if (2) friend function ->class
    // friend class B;
};

void B::doSomething(A &a)
{
    cout << a.m_value << endl;
}

// if(1)
/*
void doSomething(A &a, B &b)
{
    cout << a.m_value << " " << b.m_value << endl;
}
*/

int main()
{
    // if(1)
    /*
    A a;
    B b;
    doSomething(a, b);
    */

    A a;
    B b;

    b.doSomething(a);

    return 0;
}