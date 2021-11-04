# 솔루션

국어 영어 수학 성적의 평균을 낸 후에 기준대로 비교한다.

비교할 때 국어 영어 수학 성적의 합을 3으로 나눈 값으로 비교하면 컴파일러 환경에 따라 실수 오차가 발생할 수도 있다.

평균값을 3배해서 국어 영어 수학 성적의 합과 비교하면 정수로 정확하게 비교할 수 있다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b+c>=90*3) cout<<'A';
    else if(a+b+c>=80*3) cout<<'B';
    else if(a+b+c>=70*3) cout<<'C';
    else if(a+b+c>=60*3) cout<<'D';
    cout<<'F';
    return 0;
}
```
