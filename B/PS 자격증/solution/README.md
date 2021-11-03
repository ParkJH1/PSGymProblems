# 솔루션

A + B가 150 이상이면 `PASS` 그 외는 `FAIL`



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a+b>=150) cout<<"PASS\n";
        else cout<<"FAIL\n";
    }
    return 0;
}
```
