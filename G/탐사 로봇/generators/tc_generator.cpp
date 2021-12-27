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

int solution(int k, vector<string> v)
{
    int n=v.size(),m=v[0].size();
    vector<vector<int>> dp(n,vector<int>(m));
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
    return answer;
}

void generator_random_small(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        int n=myrand(5)+1;
        int m=myrand(5)+1;
        int k=myrand(20)+1;
        vector<string> v(n);
        osin<<n<<" "<<m<<" "<<k<<"\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(myrand(2)) v[i]+='M';
                else v[i]+='.';
            }
            osin<<v[i]<<"\n";
        }
        int answer=solution(k,v);
        osans<<answer<<"\n";
        if(answer==0) continue;
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
        int n=myrand(50)+1;
        int m=myrand(50)+1;
        int k=myrand(2500)+1;
        vector<string> v(n);
        osin<<n<<" "<<m<<" "<<k<<"\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(myrand(2)) v[i]+='M';
                else v[i]+='.';
            }
            osin<<v[i]<<"\n";
        }
        int answer=solution(k,v);
        osans<<answer<<"\n";
        if(answer==0) continue;
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_random_maximum(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_maximum"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_maximum"+zeropad(data,2)+".ans");
        int n=50;
        int m=50;
        int k=myrand(2500)+1;
        vector<string> v(n);
        osin<<n<<" "<<m<<" "<<k<<"\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(myrand(2)) v[i]+='M';
                else v[i]+='.';
            }
            osin<<v[i]<<"\n";
        }
        int answer=solution(k,v);
        osans<<answer<<"\n";
        if(answer==0) continue;
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_handmade01()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade01.in");
    osans.open(path+"secret/"+"handmade01.ans");
    int n=50;
    int m=50;
    int k=myrand(2500)+1;
    vector<string> v(n);
    osin<<n<<" "<<m<<" "<<k<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            v[i]+='.';
        }
        osin<<v[i]<<"\n";
    }
    osans<<solution(k,v)<<"\n";
    osin.close();
    osans.close();
}

void generator_handmade02()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade02.in");
    osans.open(path+"secret/"+"handmade02.ans");
    int n=50;
    int m=50;
    int k=1000;
    vector<string> v(n);
    osin<<n<<" "<<m<<" "<<k<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            v[i]+='M';
        }
        osin<<v[i]<<"\n";
    }
    osans<<solution(k,v)<<"\n";
    osin.close();
    osans.close();
}

int main()
{
    generator_random_small(10);
    generator_random_large(10);
    generator_random_maximum(2);
    generator_handmade01();
    generator_handmade02();
    return 0;
}
