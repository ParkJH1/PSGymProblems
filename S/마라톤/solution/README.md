# 솔루션

점수 기준 내림차순 정렬 후 앞 3명의 이름을 출력한다.

vector 와 pair 를 활용해서 자료를 저장하고

sort 함수로 정렬을 수행하면 코딩이 편하다.



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
    vector<pair<int,string>> v(n);
    for(int i=0; i<n; i++) cin>>v[i].second>>v[i].first;
    sort(v.rbegin(),v.rend());
    for(int i=0; i<3; i++) cout<<v[i].second<<"\n";
    return 0;
}
```
