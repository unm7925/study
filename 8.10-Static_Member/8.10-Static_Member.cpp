#include <iostream>

using namespace std;

/*int generateID()
{
    static int s_id = 0;
    return ++s_id;
}
*/

class Something
{
public:
    static constexpr int m_value = 1; // const 및 constexpr 사용가능
};

// int Something::m_value = 1; // static define in cpp ( 헤더와 분리할 경우 )

int main()
{

    cout << &Something::m_value << " " << Something::m_value << endl;

    Something st1;
    Something st2;

    st1.m_value = 2;

    cout << &st1.m_value << " " << st1.m_value << endl;

    cout << &st2.m_value << " " << st2.m_value << endl;

    Something::m_value = 1024;

    cout << &Something::m_value << " " << Something::m_value << endl;

    /*
    cout << generateID() << endl;
    cout << generateID() << endl;
    cout << generateID() << endl;
    */

    return 0;
}