# 솔루션

STL sort 함수를 이용해서 정렬한다.



# 소스코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++) cout<<v[i]<<" ";
    return 0;
}
```
