#include <fstream> // 파일 출력
#include <iostream>
using namespace std;

// in , out Operator => " << " , " >> "

class Point
{
  private:
    double m_x, m_y, m_z;

  public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z)
    {
    }

    double getX()
    {
        return m_x;
    }

    double getY()
    {
        return m_y;
    }

    double getZ()
    {
        return m_z;
    }
    /*   연산자 오버로딩 안할 시
    void print()
    {
        cout << m_x << " " << m_y << " " << m_z ;
    }
    */

    // 멤버 펑션이 아닌 경우는 멤버 연산자를 작성해줘야한다. ( ++ 좌측이 본인 클래스 인자가 아니기 때문에 멤버펑션으로
    // 하기엔 어려움 ) 출력용

    friend std::ostream &operator<<(std::ostream &out, const Point &point)
    {
        out << point.m_x << " " << point.m_y << " " << point.m_z;

        return out;
    }

    friend std::istream &operator>>(std::istream &in, Point &point)
    {
        in >> point.m_x >> point.m_y >> point.m_z;

        return in;
    }
};

int main()
{

    ofstream of("out.txt");
    // 해당 cpp이 있는 위치에 위의 파일이 생성됌 ( 연산자를 사용해 출력한 상태로 )

    // 출력용 예시
    // Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

    // 입력용 예시
    Point p1, p2;

    cin >> p1 >> p2;

    /*
    연산자 오버로딩 안할 시
    p1.print();
    cout << " ";
    p2.print();
    cout << endl;
    */

    cout << p1 << " " << p2;
    of << p1 << " " << p2;
    of.close();

    return 0;
}