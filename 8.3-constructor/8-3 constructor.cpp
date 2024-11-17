// 생성자
#include <iostream>

using namespace std;

class Fraction
{
private:
    int m_numverator;
    int m_denominator;

public:
    // 생성자를 선언 안하면 아무일도 안하는 디폴트 생성자가 생략되어 있는 것으로 간주 Fraction(){}
    // 생성자가 생성을 하는 것 이 아닌 생성이 될 때 자동 실행되는 함수일 뿐이다.
    Fraction(const int &num_in, const int &den_in)
    // 생성자 -> 다른 곳에서 선언을 할 경우 불러오면서 첫번째로 바로 실행
    // 생성자의 파라미터 모두 디폴트 값이 있을 경우엔 파라미터가 없는 경우로도 사용가능 오버로딩 주의
    {
        m_numverator = num_in;
        m_denominator = den_in;
    }
    void print()
    {
        cout << m_numverator << " / " << m_denominator << endl;
    }
};

int main()
{
    // Fraction frac; // 생성자의 파라미터가 없을경우엔 기존의 함수처럼 ()를 사용하지않음.
    // frac.print();
    Fraction one_thirds{1, 3}; // 타입변환 허용 x
    Fraction one_thirds(1, 3); // 경고는 뜨지만 컴파일은 가능
    // 파라미터의 값이 지정되어있으면 매개변수를 넣지 않을 때 디폴트 값으로 지정되어사용
    // Fraction one_thirds(1); -- > 매개변수 &den_in = 1 되어있다면 1/1로 출력
    one_thirds.print();
    return 0;
}