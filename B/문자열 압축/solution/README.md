# 솔루션

이전과 다른 문자가 등장했을 때까지 센 문자의 개수가 5이상이면 이전 문자하나와 괄호 속 숫자로 출력하고, 5미만이면 그 횟수만큼 다시 반복하면서 이전 문자를 출력한다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cnt=1;
    for(int i=1; i<=s.length(); i++){
        if(i==s.length() || s[i]!=s[i-1]){
            if(cnt>=5) cout<<s[i-1]<<"("<<cnt<<")";
            else for(int j=0; j<cnt; j++) cout<<s[i-1];
            cnt=1;
        }
        else cnt+=1;
    }
    return 0;
}
```
