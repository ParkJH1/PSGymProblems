# 솔루션

2로 나눈 나머지가 1인 경우 홀수, 0인 경우 짝수다.

% 연산을 이용해서 구한다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==1) cout<<"Odd\n";
        else cout<<"Even\n";
    }
    return 0;
}
```
