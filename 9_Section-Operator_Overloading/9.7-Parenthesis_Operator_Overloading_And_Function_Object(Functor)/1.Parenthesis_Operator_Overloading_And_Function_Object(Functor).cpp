#include <iostream>

using namespace std;


// 괄호 연산자는 특징상 함수를 사용하는 것과 같아서 
// 괄호 연산자를 오버로딩하면 함수를 객체처럼 사용 가능하다

class Accumulator
{
    private:
        int m_counter = 0;
    public:
        // 받아오는 수를 더하는 함수역할을 수행 함 이러한 형태를 functor라 부름
        int operator ()(int i) {return (m_counter +=i);}
};
int main()
{
    Accumulator acc;

    cout << acc(10) << endl;
    cout << acc(20) << endl;



    return 0;
}