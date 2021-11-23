# 솔루션

1부터 N까지 돌면서 N을 나누었을 때 나머지가 0인 값을 차례대로 출력한다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) if(n%i==0) cout<<i<<" ";
    return 0;
}
```
