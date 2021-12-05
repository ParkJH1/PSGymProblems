# 솔루션

등장하는 색을 set 자료구조를 활용해서 중복없이 센다.

set에 저장할 데이터는 R, G, B 3개의 정보를 그대로 담은 배열이나 pair 구조를 활용하는 것이 확실하다.



# 소스코드

```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    set<vector<int>> s;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vector<int> v(3);
            for(int k=0; k<3; k++) cin>>v[k];
            s.insert(v);
        }
    }
    cout<<s.size();
    return 0;
}
```
