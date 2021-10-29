# 솔루션

-9999를 초기값으로 설정한 변수와 주어진 정수를 하나씩 비교해보며 더 큰 경우 갱신한다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int answer=-9999;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(answer<a) answer=a;
    }
    cout<<answer;
    return 0;
}
```
