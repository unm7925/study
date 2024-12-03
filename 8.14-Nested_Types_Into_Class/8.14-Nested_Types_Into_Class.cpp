#include <iostream>

class Fruit
{
  public:                // 다양한 곳에서 사용 된다면 헤더파일에 빼서 쓰면 된다.
    enum class FruitType // 특정 클래스에서만 사용 될 경우는 클래스 안에 타입선언을 넣는다.
    {
        APPLE,
        BANANA,
        CHERRY,
    };

    class InnerClass
    {
    };
    struct InnerStruct
    {
    };

  private:
    FruitType m_type;

  public:
    Fruit(FruitType type) : m_type(type)
    {
    }

    FruitType getType()
    {
        return m_type;
    }
};

int main()
{
    Fruit apple(Fruit::FruitType::APPLE);

    if (apple.getType() == Fruit::FruitType::APPLE)
    {
        std::cout << "Apple" << std::endl;
    }

    return 0;
}