# 솔루션

동적계획법

`dp[i][j][k] = 1~i번 수 중 j개를 사용해서 합이 k가 되도록 만드는 경우의 수`

- 1~i-1번 수까지 사용해서 만든 경우의 수
- i번째 수만 사용하는 경우의 수
- i번째 수를 추가해서 사용하는 경우의 수

3가지를 더하는 점화식을 세우면 O(50 * 50 * 2500) 의 시간복잡도로 구현이 가능하다.



# 소스코드

```cpp
#include <iostream>
#include <vector>

using namespace std;
using ll=long long;

int main()
{
    int n,a;
    cin>>n>>a;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2501)));
    dp[0][0][v[0]]=1;
    for(int i=1; i<n; i++){
        dp[i][0][v[i]]+=1;
        for(int j=0; j<n; j++) for(int k=0; k<=2500; k++) dp[i][j][k]+=dp[i-1][j][k];
        for(int j=0; j<n-1; j++) for(int k=0; k<=2500; k++) dp[i][j+1][v[i]+k]+=dp[i-1][j][k];
    }
    ll answer=0;
    for(int i=0; i<n; i++) answer+=dp[n-1][i][a*(i+1)];
    cout<<answer;
    return 0;
}
```
