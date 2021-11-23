# 솔루션

a와 A의 아스키코드 차이만큼 더하고 빼는 것을 활용해서 대소문자 변환을 구현한다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a') s[i]-='a'-'A';
        else s[i]+='a'-'A';
    }
    cout<<s;
    return 0;
}
```
