# 솔루션

A부터 B까지 전부 보면서 소수인 수들을 차례대로 출력한다.

소수인 수가 하나도 없으면 `X` 를 출력한다.

어떤 수 X가 소수인지 판별하는 것은 2부터 X-1까지 나눠보면서 나누어 떨어지는 수가 하나라도 있으면 소수가 아니다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    bool check=false;
    for(int i=a; i<=b; i++){
        bool p=true;
        for(int j=2; j<i; j++) if(i%j==0) p=false;
        if(p){
            cout<<i<<" ";
            check=true;
        }
    }
    if(!check) cout<<"X";
    return 0;
}
```
