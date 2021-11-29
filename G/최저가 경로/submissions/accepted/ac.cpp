#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    vector<vector<char>> d(n,vector<char>(n));
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
                    d[i-1][j]='D';
                }
            }
            if(j>0){
                if(dp[i][j]>dp[i][j-1]){
                    dp[i][j]=dp[i][j-1];
                    d[i][j-1]='R';
                }
            }
            dp[i][j]+=v[i][j];
        }
    }
    cout<<dp[n-1][n-1]<<"\n";
    string s;
    int ny=0,nx=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
    while(true){
        if(ny==n-1 && nx==n-1) break;
        cout<<d[ny][nx];
        if(d[ny][nx]=='R') nx+=1;
        if(d[ny][nx]=='D') ny+=1;
    }

    return 0;
}
