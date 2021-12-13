# 솔루션

투 포인터, 그리디

2톤 짜리 컨테이너와 1톤 짜리 컨테이너의 사용할 개수를 결정하면 그 상황에서 가장 높은 가격은 높은 가격부터 차례대로 골라서 찾을 수 있다.

2톤 짜리 컨테이너를 최대한 쓴 상태를 만들어두고 2톤 짜리를 하나씩 없애면서 남은 공간을 1톤 짜리 컨테이너로 채우는 식으로 답을 구해가면서 그 답 중 가장 큰 가격을 찾는다.



# 소스코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v1,v2;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        if(a==1) v1.push_back(b);
        else v2.push_back(b);
    }
    int answer=0;
    int now=0;
    int cnt=0;
    sort(v1.rbegin(),v1.rend());
    sort(v2.rbegin(),v2.rend());
    int i=0,j=0;
    for(; i<v2.size(); i++){
        if(cnt+2>m) break;
        now+=v2[i];
        cnt+=2;
    }
    for(; j<v1.size(); j++){
        if(cnt+1>m) break;
        now+=v1[j];
        cnt+=1;
    }
    answer=now;
    while(i--){
        now-=v2[i];
        cnt-=2;
        for(; j<v1.size(); j++){
            if(cnt+1>m) break;
            now+=v1[j];
            cnt+=1;
        }
        answer=max(answer,now);
    }
    cout<<answer;
    return 0;
}
```
