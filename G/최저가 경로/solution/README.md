# 솔루션

매 상황마다 선택지가 오른쪽 또는 아래쪽이기 때문에 반대로 생각하면 현재 칸에 도달하는 이전 상황은 왼쪽 또는 위쪽 2곳이다.

이 점을 활용하면 `dp[i][j] = (i,j)에 도달하는 최저 비용` 으로 정의해서 점화식을 세워 값을 채울 수 있다.

비용이 int 범위를 초과할 수 있으므로 long long 을 사용해야한다.



# 소스코드

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<long long>> v(n,vector<long long>(n));
    vector<vector<long long>> dp(n,vector<long long>(n,LLONG_MAX));
    vector<vector<char>> d(n,vector<char>(n,'-'));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    dp[0][0]=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>0){
                if(dp[i][j]>dp[i-1][j]){
                    dp[i][j]=dp[i-1][j];
                    d[i][j]='D';
                }
            }
            if(j>0){
                if(dp[i][j]>dp[i][j-1]){
                    dp[i][j]=dp[i][j-1];
                    d[i][j]='R';
                }
            }
            dp[i][j]+=v[i][j];
        }
    }
    cout<<dp[n-1][n-1]<<"\n";
    string p;
    int ny=n-1,nx=n-1;
    while(true){
        if(ny==0 && nx==0) break;
        p+=d[ny][nx];
        if(d[ny][nx]=='R') nx-=1;
        else ny-=1;
    }
    reverse(p.begin(),p.end());
    cout<<p;

    return 0;
}
```
