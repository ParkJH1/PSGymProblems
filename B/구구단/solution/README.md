# 솔루션

구구단의 N단을 출력한다.

반복문으로 구현하면 편리하다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=9; i++) cout<<n<<" x "<<i<<" = "<<n*i<<"\n";
    return 0;
}
```
