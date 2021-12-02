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
                }
            }
            if(j>0){
                if(dp[i][j]>dp[i][j-1]){
                    dp[i][j]=dp[i][j-1];
                }
            }
            dp[i][j]+=v[i][j];
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}
