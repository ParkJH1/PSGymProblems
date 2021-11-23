# 솔루션

최대공약수는 1부터 최대 범위인 100까지 돌면서 공약수인 수들 중 가장 큰 수를 찾아낸다.

최소공배수는 1부터 최대 범위인 10,000까지 돌면서 공배수인 수들 중 가장 작은 수를 찾아낸다.

다른 방법으로는 유클리드 호제법을 사용해서 최대공약수를 구한 후, 최소공배수는 그 성질을 이용해서 두 수의 곱에서 최대공약수를 나누는 방식으로 구해낸다.

아래 코드는 유클리드 호제법을 이용해 구하는 방법이다.


# 소스코드

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return (a%b==0)?b:gcd(b,a%b);
}

int main()
{
    int a,b;
    cin>>a>>b;
    int g=gcd(a,b);
    cout<<g<<" "<<a*b/g;
    return 0;
}
```
