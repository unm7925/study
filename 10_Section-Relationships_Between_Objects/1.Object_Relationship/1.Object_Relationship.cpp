#include <iostream>

using namespace std;

/*                          관계를 표현하는 동사    관계의 형태    방향성                 다른클래스에 속할 수 있는가?
   멤버의 존재를 클래스가 관리     예시 구성(요소) Composition -> Part-of ->         전체/부품      단방향 No   (나의
   뇌는 내 몸에만 )    Yes                     `두뇌`는 육체의 일부이다. 집합 Aggregation      -> Has-a 전체/부품 단방향
   Yes  (내 차는 공유가능 )      No                      어떤 사람이 `자동차`를 가지고 있다. 연계, 제휴  Association->
   Uses-a             용도 외 무관    단방향 or 양방향        Yes   (다른 의사, 환자 )      No 환자는 `의사`의 치료를
   받는다, 의사는 `환자들`로부터 치료비를 받는다. 의존 Dependency (필요할때만)  -> Depends-on    용도 외 무관    단방향
   Yes  (목발 말고 다른 거 )      Yes                      나는(다리가 부러져서 한 달 동안) `목발`을 짚었다.
*/

int main()
{

    return 0;
}