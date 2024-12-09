#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Cents
{
  private:
    int m_cents;

  public:
    Cents(int cents = 0)
    {
        m_cents = cents;
    }
    int getCents() const
    {
        return m_cents;
    }

    int &getCents()
    {
        return m_cents;
    }

    /*
    bool operator==(const Cents &c2)
    {
        return this->m_cents == c2.m_cents;
    }
    friend bool operator!=(const Cents &c1, const Cents &c2)
    {
        return c1.m_cents != c2.m_cents;
    }
    */

    // sort에 사용하기 위해선 왼쪽이 더 작냐 로 비교해야함 ( < ) 내부를 다르게하면 버그가 날 수도 있음 일단 < 하면
    // 오름차순 >하면 내림차순임
    friend bool operator<(const Cents &c1, const Cents &c2)
    {
        return c1.m_cents < c2.m_cents;
    }

    friend std::ostream &operator<<(std::ostream &out, const Cents &cents)
    {
        out << cents.m_cents;

        return out;
    }
};

int main()
{
    Cents cents1(6);
    Cents cents2(0);

    vector<Cents> arr(20);
    for (unsigned i = 0; i < 20; ++i)
    {
        arr[i].getCents() = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);

    for (auto &e : arr)
    {
        cout << e << " ";
    }
    cout << endl;

    std::sort(arr.begin(), arr.end());

    // cout << std::boolalpha;

    return 0;
}