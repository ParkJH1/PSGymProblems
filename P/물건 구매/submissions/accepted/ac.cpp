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
