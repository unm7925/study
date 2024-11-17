// this 포인터와 연쇄 호출
#include <iostream>

using namespace std;

class Simple
{
private:
    int m_id;

public:
    Simple(int id)
    {
        setID(id); // this->setID(id) 와 동일함 , this-> 가 생략되어 있는 상태
                   // ->는 상대가 클래스나 구조체일 경우 선택해주는 오퍼레이터
        m_id;

        cout << this << endl;
    }

    void setID(int id) { m_id = id; }
    int getID() { return m_id; }
};

int main()
{
    Simple s1(1), s2(2);
    s1.setID(2);
    s2.setID(4);

    cout << &s1 << " " << &s2 << endl;

    // Simple::setID(&s1, 1); 이런식으로 실행됌 == s1.setID(1);
    return 0;
}