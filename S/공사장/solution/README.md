# 솔루션

완전탐색

N개 중 1개부터 N개까지 선택하는 모든 경우의 수를 다 탐색해보면서 총 무게가 K인 개수를 센다.



# 소스코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,a;
    cin>>n>>a;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> b(n);
    int answer=0;
    for(int i=0; i<n; i++){
        b[n-1-i]=1;
        do{
            int sum=0;
            for(int j=0; j<n; j++) if(b[j]) sum+=v[j];
            if(sum==a) answer+=1;
        }while(next_permutation(all(b)));
    }
    cout<<answer;
    return 0;
}
```
