#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>
#include <fstream>
#include <unistd.h>
#include <random>
#include <chrono>

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using pii=pair<int,int>;
using ll=long long;

string path="../data/";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myrand(ll B) {
	return (unsigned long long)rng() % B;
}

string zeropad(int n, int d)
{
    string ret=to_string(n);
    while(ret.length()<d) ret="0"+ret;
    return ret;
}

pair<ll,string> solution(vector<vector<int>> v)
{
    int n=v.size();
    vector<vector<ll>> dp(n,vector<ll>(n,LLONG_MAX));
    vector<vector<char>> d(n,vector<char>(n));
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
    string p;
    int ny=n-1,nx=n-1;
    while(true){
        if(ny==0 && nx==0) break;
        p+=d[ny][nx];
        if(d[ny][nx]=='D') ny-=1;
        else nx-=1;
    }
    reverse(all(p));
    return {dp[n-1][n-1],p};
}

void generator_random_small(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        int n=myrand(9)+2;
        osin<<n<<"\n";
        vector<vector<int>> v(n,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                v[i][j]=myrand(100)+1;
                osin<<v[i][j]<<" ";
            }
            osin<<"\n";
        }
        pair<ll,string> answer=solution(v);
        osans<<answer.ff<<"\n"<<answer.ss<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_random_large(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_large"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_large"+zeropad(data,2)+".ans");
        int n=myrand(999)+2;
        osin<<n<<"\n";
        vector<vector<int>> v(n,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                v[i][j]=myrand(1000000000)+1;
                osin<<v[i][j]<<" ";
            }
            osin<<"\n";
        }
        pair<ll,string> answer=solution(v);
        osans<<answer.ff<<"\n"<<answer.ss<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    generator_random_small(10);
    generator_random_large(10);
    return 0;
}
