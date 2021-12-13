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

int solution(int m, vector<pii> v)
{
    int n=v.size();
    vector<int> v1,v2;
    for(int i=0; i<n; i++){
        int a=v[i].ff,b=v[i].ss;
        if(a==1) v1.push_back(b);
        else v2.push_back(b);
    }
    int answer=0;
    int now=0;
    int cnt=0;
    sort(v1.rbegin(),v1.rend());
    sort(v2.rbegin(),v2.rend());
    int i=0,j=0;
    for(; i<v2.size(); i++){
        if(cnt+2>m) break;
        now+=v2[i];
        cnt+=2;
    }
    for(; j<v1.size(); j++){
        if(cnt+1>m) break;
        now+=v1[j];
        cnt+=1;
    }
    answer=now;
    while(i--){
        now-=v2[i];
        cnt-=2;
        for(; j<v1.size(); j++){
            if(cnt+1>m) break;
            now+=v1[j];
            cnt+=1;
        }
        answer=max(answer,now);
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
        int n=myrand(100)+1;
        int m=myrand(100)+1;
        osin<<n<<" "<<m<<"\n";
        vector<pii> v(n);
        for(int i=0; i<n; i++){
            v[i]={myrand(2)+1,myrand(10000)+1};
            osin<<v[i].ff<<" "<<v[i].ss<<"\n";
        }
        osans<<solution(m,v)<<"\n";
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
        int n=myrand(100000)+1;
        int m=myrand(500000)+1;
        osin<<n<<" "<<m<<"\n";
        vector<pii> v(n);
        for(int i=0; i<n; i++){
            v[i]={myrand(2)+1,myrand(10000)+1};
            osin<<v[i].ff<<" "<<v[i].ss<<"\n";
        }
        osans<<solution(m,v)<<"\n";
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
        int n=100000;
        int m=500000;
        osin<<n<<" "<<m<<"\n";
        vector<pii> v(n);
        for(int i=0; i<n; i++){
            v[i]={myrand(2)+1,myrand(10000)+1};
            osin<<v[i].ff<<" "<<v[i].ss<<"\n";
        }
        osans<<solution(m,v)<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    generator_random_small(10);
    generator_random_large(10);
    generator_random_maximum(2);
    return 0;
}
