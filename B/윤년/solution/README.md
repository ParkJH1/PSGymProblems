# 솔루션

윤년의 조건을 나머지 연산을 활용해서 그대로 조건문으로 구현하면 된다.



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
        if(n%400==0 || (n%100!=0 && n%4==0)) cout<<"LEAP\n";
        else cout<<"COMMON\n";
    }
    return 0;
}
```
