// RVO == Return Value Optimization

#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1)
        : m_numerator(num), m_denominator(den)
    {
        assert(den != 0);
    }
    // 복사 생성자는 복사 초기화에 같이 사용된다.
    Fraction(const Fraction &fraction) // copy constructor , private 로 넣으면 외부에서 접근 안됌
        : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
    {
        cout << "Copy constructor Called" << endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f)
    {
        out << f.m_numerator << " / " << f.m_denominator << endl;
        return out;
    }
};

Fraction doSomething()
{
    Fraction temp(1, 2);
    return temp;
}

int main()
{
    Fraction frac(3, 5);
    // 1
    // Fraction fr_copy(frac);
    // 2
    Fraction fr_copy = frac;

    Fraction fr_copy2(Fraction(5, 3)); // copy가 아님

    Fraction result = doSomething(); // <- 디버그는 카피, 릴리즈는 카피아님
    // 왜냐하면 temp가 범위 밖으로 사라지면 필요가 없어지기 때문에 값을 그냥 넣어서 삭제해줌 (컴파일러 기능 중 하나)
    // 증거로 디버그로 하면 result와 temp의 주소값이 다르지만 릴리즈로 하면 같음

    cout << frac << " " << fr_copy << " " << result << endl;

    return 0;
}