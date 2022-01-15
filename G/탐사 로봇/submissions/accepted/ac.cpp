#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> v(n);
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=0; i<n; i++) cin>>v[i];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i>0) dp[i][j]+=dp[i-1][j];
            if(j>0) dp[i][j]+=dp[i][j-1];
            if(i>0 && j>0) dp[i][j]-=dp[i-1][j-1];
            if(v[i][j]=='M') dp[i][j]+=1;
        }
    }

    int answer=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k1=i; k1<n; k1++){
                for(int k2=j; k2<m; k2++){
                    int cnt=dp[k1][k2];
                    if(i>0) cnt-=dp[i-1][k2];
                    if(j>0) cnt-=dp[k1][j-1];
                    if(i>0 && j>0) cnt+=dp[i-1][j-1];
                    if(cnt==k) answer+=1;
                }
            }
        }
    }
    cout<<answer;

    return 0;
}
