#include <iostream>

using namespace std;

class Calc
{
private:
    int m_value;

public:
    Calc(int init_value)
        : m_value(init_value)
    {
    }

    Calc &add(int value)
    {
        m_value += value;
        return *this;
    }
    Calc &sub(int value)
    {
        m_value -= value;
        return *this;
    }
    Calc &mult(int value)
    {
        m_value *= value;
        return *this;
    }

    void print()
    {
        cout << m_value << endl;
    }
};

int main()
{
    Calc cal(10);
    cal.add(10);
    cal.sub(1);
    cal.mult(2);
    cal.print();

    // 멤버펑션 체이닝 연쇄 호출
    // 외부
    Calc cal1(10);
    cal1.add(10).sub(1).mult(2).print();

    // 내부
    Calc cal2(10);
    Calc &temp1 = cal2.add(10);
    Calc &temp2 = temp1.sub(1);
    Calc &temp3 = temp2.mult(2);
    temp3.print();

    // 컴퓨터 성능이 좋아지고 있어서 괜찮은 것 같기도? 물론 기존의 것 보다 메모리는 더 쓰겠지만
    // 일단 가독성이 좋음 걍 편해보여 근데 흠..
    // 좀 큰 프로젝트들이나 그런 것 맡을 땐 이런게 어디서 쓰일지는 모르겠음.
    // 내가 초보라 내가 취준이라 나는 아무고토 몰라 홍정모선생님도 잘 모르겠다고 했어

    return 0;
}