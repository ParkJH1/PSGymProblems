# 솔루션

1부터 N까지 반복하며 K로 나누어 떨어지는 값만 누적한다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int answer=0;
    for(int i=1; i<=n; i++){
        if(i%k==0) answer+=i;
    }
    cout<<answer;
    return 0;
}
```
