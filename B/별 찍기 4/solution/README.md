# 솔루션

윗 부분, 아랫 부분 삼각형 두개로 나누어서 각 줄에 필요한 공백과 별의 개수의 규칙을 찾아낸다.



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
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<n-1-i; j++) cout<<" ";
        for(int j=0; j<2*i+1; j++) cout<<"*";
        cout<<"\n";
    }
    return 0;
}
```
