# 솔루션

0번째 줄부터 기준으로 봤을 때, i번째 줄에 공백 N-1-i개, 별 2*i+1개를 출력하는 규칙을 이중 for문으로 구현한다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++) cout<<" ";
        for(int j=0; j<2*i+1; j++) cout<<"*";
        cout<<"\n";
    }
    return 0;
}
```
