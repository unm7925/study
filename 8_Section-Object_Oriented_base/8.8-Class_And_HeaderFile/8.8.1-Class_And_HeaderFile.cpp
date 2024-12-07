
#include "Calc.h" // 내가만들면 " " 상용화된것들은 < >

int main()
{
    Calc cal(10);
    cal.add(10);
    cal.sub(1);
    cal.mult(2);
    cal.print();

    Calc cal1(10);
    cal1.add(10).sub(1).mult(2).print();

    Calc cal2(10);
    Calc &temp1 = cal2.add(10);
    Calc &temp2 = temp1.sub(1);
    Calc &temp3 = temp2.mult(2);
    temp3.print();

    return 0;
}