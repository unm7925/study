#include <iostream>
#include <cassert>

using namespace std;

class IntList
{
private:
    int m_list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

public:
    int &operator[](const int index) // 자료형 아무거나 다 써도 됌
    {
        assert(index >= 0);
        assert(index < 10);
        return m_list[index];
    }
    const int &operator[](const int index) const
    {
        assert(index >= 0);
        assert(index < 10);
        return m_list[index];
    }

    /* 기초적인 구성 상황
    void setItem(int index, int value)
    {
        m_list[index] = value;
    }

    int getItem(int index)
    {
        return m_list[index];
    }
    */

    /* 포인터로 배열 받아오기 ( 배열은 애초에 포인터 역할을 지님 )
    int *getList()
    {
        return m_list;
    }
    */
};

int main()
{
    IntList *list = new IntList;

    // list[3] = 10; // list 자체의 어레이를 스퀘어 브레이크 접근 시도가 되기 때문에 디레퍼러싱 해야함
    (*list)[3] = 10; // ok

    // 인스턴스를 생성할때 const로 생성할 때는 오버로딩또한 const로 하나 더 만들어서 세부적 활용 가능
    IntList my_list;

    my_list[3] = 10;

    cout << my_list[3] << endl;

    /* 기초적인 실행 상황
    my_list.setItem(3,1);
    cout << my_list.getItem(3) << endl;
    my_list.getList()[3] = 10;
    cout << my_list.getList()[3] << endl;
    */

    return 0;
}