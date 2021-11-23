# 솔루션

10000의 자릿수는 n을 10000으로 나눈 몫이고, 자릿값은 그 수에 10000을 곱해서 구한다.

같은 방식으로 1000, 100, 10, 1의 자리의 자릿값을 구한다.



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
        int tmp=10000;
        bool check=true;
        while(tmp!=0){
            if(n/tmp!=0) check=false;
            if(!check){
                cout<<n/tmp*tmp<<" ";
                n=n-n/tmp*tmp;
            }
            tmp/=10;
        }
        cout<<"\n";
    }

    return 0;
}
```
