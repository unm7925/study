#include <iostream>

using namespace std;

class Something
{
public:
    string m_value = "default";

    const string &getValue() const { return m_value; }
    string &getValue() { return m_value; }
};

int main()
{

    Something something;
    something.getValue() = 10;

    const Something something2;
    something2.getValue();

    // const 를 활용한 오버로딩 가능 -> 자주안씀
    return 0;
}