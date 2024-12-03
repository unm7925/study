#include <iostream>
using namespace std;

class Something
{
public:

	class _init
	{
	public:
		_init()
		{
			s_value = 9876; // 이런식으로 세부적으로 받아내면 할 수 있음
		}
	};

private:
	static int s_value;
	int m_value;

	static _init s_initalizer;

public:
	Something() // static은 생성자에서 선언불가 정확히는 static 생성자를 생성불가
		:m_value(123)//, s_value(1024)
	{}

	static int getValue()
	{
		return s_value;							// 정적함수에서는 this 사용 불가
												// 정적변수 외에도 안됌 왜냐하면 this->는 생략되어있으니까
	}

	int temp()
	{
		return this->s_value;// + this-> m_value; // 특정 인스턴스에 해당하는 멤버변수 주소 사용
	}
};

int Something::s_value;
Something::_init Something::s_initalizer;

int main()
{
	cout << Something::getValue()  << endl;

	Something s1,s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;

	int (Something:: * fptr1)() = &Something::temp;

	cout << (s2.*fptr1)() << endl;

	int (* fptr2)() = &Something::getValue;

	cout << fptr2() << endl;

	return 0;
}
