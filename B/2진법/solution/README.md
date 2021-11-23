# 솔루션

2로 나눈 나머지로 2진법으로 표현했을 때 마지막 자리수를 알 수 있다.

마지막 자리수를 구하고 수를 2로 나누는 작업을 0이 될 때까지 반복한다.

그렇게 구한 자리수들을 거꾸로 출력하면 된다.



# 소스코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    while(n>0){
        s+='0'+n%2;
        n/=2;
    }
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}
```
