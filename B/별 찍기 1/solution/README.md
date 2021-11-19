# 솔루션

별을 N개 출력한다.



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
        while(n--) cout<<"*";
        cout<<"\n";
    }
    return 0;
}
```
