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

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

using namespace std;
using pii=pair<int,int>;
using ll=long long;

string path="../data/";

string zeropad(int n, int d)
{
    string ret=to_string(n);
    while(ret.length()<d) ret="0"+ret;
    return ret;
}

ll solution(int n, int a, vector<int> v)
{
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2501)));
    dp[0][0][v[0]]=1;
    for(int i=1; i<n; i++){
        dp[i][0][v[i]]+=1;
        for(int j=0; j<n; j++) for(int k=0; k<=2500; k++) dp[i][j][k]+=dp[i-1][j][k];
        for(int j=0; j<n-1; j++) for(int k=0; k<=2500; k++) dp[i][j+1][v[i]+k]+=dp[i-1][j][k];
    }
    ll answer=0;
    for(int i=0; i<n; i++) answer+=dp[n-1][i][a*(i+1)];
    return answer;
}

void generator_random_small(int datacnt)
{
    int data=1;
    int z=0;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        int n=rand()%10+1;
        int k=rand()%50+1;
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i]=rand()%50+1;
        osin<<n<<" "<<k<<"\n";
        for(int i=0; i<n; i++) osin<<v[i]<<" ";
        osin<<"\n";
        ll answer=solution(n,k,v);
        osans<<answer<<"\n";
        if(answer!=0 || (answer==0 && z==0)) data+=1;
        if(answer==0) z=1;
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
        int n=rand()%50+1;
        int k=rand()%50+1;
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i]=rand()%50+1;
        osin<<n<<" "<<k<<"\n";
        for(int i=0; i<n; i++) osin<<v[i]<<" ";
        osin<<"\n";
        osans<<solution(n,k,v)<<"\n";
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
    osin<<"33 3\n3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n";
    osans<<"8589934591\n";
    osin.close();
    osans.close();
}

void generator_handmade02()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade02.in");
    osans.open(path+"secret/"+"handmade02.ans");
    int n=10;
    int k=5;
    vector<int> v(n);
    for(int i=0; i<n; i++) v[i]=5;
    osin<<n<<" "<<k<<"\n";
    for(int i=0; i<n; i++) osin<<v[i]<<" ";
    osin<<"\n";
    osans<<solution(n,k,v)<<"\n";
    osin.close();
    osans.close();
}

void generator_handmade03()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade03.in");
    osans.open(path+"secret/"+"handmade03.ans");
    int n=50;
    int k=50;
    vector<int> v(n);
    for(int i=0; i<n; i++) v[i]=50;
    osin<<n<<" "<<k<<"\n";
    for(int i=0; i<n; i++) osin<<v[i]<<" ";
    osin<<"\n";
    osans<<solution(n,k,v)<<"\n";
    osin.close();
    osans.close();
}

int main()
{
    srand((unsigned)time(NULL));
    generator_random_small(10);
    // generator_random_large(10);
    // generator_handmade01();
    // generator_handmade02();
    // generator_handmade03();
    return 0;
}
