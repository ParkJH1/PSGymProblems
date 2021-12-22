#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> v(n);
    vector<vector<int>> dp(n,vector<int>(m));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i>0) dp[i][j]+=dp[i-1][j];
            if(j>0) dp[i][j]+=dp[i][j-1];
            if(i>0 && j>0) dp[i][j]-=dp[i-1][j-1];
            if(v[i][j]=='M') dp[i][j]+=1;
        }
    }

    for(int i=0; i<n; )

    return 0;
}
