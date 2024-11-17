// 위임 생성자
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int m_id;
    string m_name;

public: // 같은 기능은 한 곳에서만 하는게 좋다. 아니 그렇게 해라.
    Student(const string &name_in)
    // : m_id(0), m_name(name_in) 비추천
    //   : Student(0, name_in) // 위임 생성자
    {
        init(0, name_in);
    }

    Student(const int &id_in, const string &name_in)
    //    : m_name(name_in)
    {
        init(id_in, name_in);
    }

    // 만능 초기화 함수 생성하는것도 좋음
    void init(const int &id_in, const string &name_in)
    {
        m_id = id_in;
        m_name = name_in;
    }
    void print()
    {
        cout << m_id << " " << m_name << endl;
    }
};

int main()
{

    Student st1(0, "Jack Jack");
    st1.print();

    Student st2("Dash");
    st2.print();

    return 0;
}