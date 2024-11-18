#include <iostream>

using namespace std;

class Something
{
public:
    int m_value = 0;
    Something(const Something &st_in) // copy constructor 이미 생략되어있음
    {
        m_value = st_in.m_value;
    }
    Something()
    {
        cout << "Constructor" << endl;
    }

    void setValue(int value) { m_value = value; }
    int getValue() const { return m_value; }
};

void print(const Something &st)
{
    cout << &st << endl;

    cout << st.getValue() << endl;
}

int main()
{

    Something something;
    print(something);
    // const Something something;
    //  클래스의 인스턴스를 const로 할당할 경우엔 사용하는 함수또한 const가 되어있어야한다.
    //  훗날에 const를 쓸 수 있는 곳은 쓰는게 좋다.
    //  something.setValue(3);

    // cout << something.getValue() << endl;

    return 0;
}