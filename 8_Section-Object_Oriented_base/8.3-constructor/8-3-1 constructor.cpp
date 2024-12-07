#include <iostream>

using namespace std;

class Second
{
public:
    Second()
    {
        cout << "class Second constructor()" << endl;
    }
};
class First
{
    Second sec; // 클래스안에 다른 클래스가 자신의 멤버로 사용 할 경우 해당 클래스의 생성자가 먼저 호출된다.

public:
    First()
    {
        cout << " class First constructor()" << endl;
    }
};

int main()
{
    First fir;

    return 0;
}