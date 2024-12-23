#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(char) = delete; // 해당 자료형이 인수로 들어오는 것을 막음

    Fraction(int num = 0, int den = 1) // explicit 를 사용하면 converting constructor의 기능을 막음.
        : m_numerator(num), m_denominator(den)
    {
        assert(den != 0);
    }

    Fraction(const Fraction &fraction)
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

void doSomething(Fraction frac)
{
    cout << frac << endl;
}

int main()
{
    Fraction frac(7);

    doSomething(7);
    // doSomething(8) -> explicit 가 적용되지 않은 생성자는 converting constructor 기에 사용 가능하지만
    //                   explicit 가 적용되면 형식에 맞게 사용해야함.

    return 0;
}