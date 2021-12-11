#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<long long>> v;
vector<vector<long long>> dp;

long long f(int y, int x)
{
    if(y<0 || x<0) return LLONG_MAX;
    if(dp[y][x]!=0) return dp[y][x];
    long long a=f(y-1,x);
    long long b=f(y,x-1);
    if(a<b) return dp[y][x]=a+v[y][x];
    return dp[y][x]=b+v[y][x];
}

int main()
{
    int n;
    cin>>n;
    v.resize(n,vector<long long>(n));
    dp.resize(n,vector<long long>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    dp[0][0]=v[0][0];
    cout<<f(n-1,n-1);
    return 0;
}
