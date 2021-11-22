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

int solution(int n, vector<pair<int,int>> v)
{
    set<pii> s;
    for(int i=0; i<n; i++){
        int x=v[i].ff,y=v[i].ss;
        for(int j=-1; j<=1; j++){
            for(int k=-1; k<=1; k++){
                s.insert({x+j,y+k});
            }
        }
    }
    return s.size();
}

void generator_random_small(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        int n=myrand(10)+1;
        osin<<n<<"\n";
        set<pii> s;
        vector<pii> v(n);
        for(int i=0; i<n; i++){
            while(true){
                pii p={myrand(10)+1,myrand(10)+1};
                if(s.insert(p).second){
                    v[i]=p;
                    break;
                }
            }
            osin<<v[i].ff<<" "<<v[i].ss<<"\n";
        }
        osans<<solution(n,v)<<"\n";
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
        osin<<n<<"\n";
        set<pii> s;
        vector<pii> v(n);
        for(int i=0; i<n; i++){
            while(true){
                pii p={myrand(1000000000)+1,myrand(1000000000)+1};
                if(s.insert(p).second){
                    v[i]=p;
                    break;
                }
            }
            osin<<v[i].ff<<" "<<v[i].ss<<"\n";
        }
        osans<<solution(n,v)<<"\n";
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
        osin<<n<<"\n";
        set<pii> s;
        vector<pii> v(n);
        for(int i=0; i<n; i++){
            while(true){
                pii p={myrand(1000000000)+1,myrand(1000000000)+1};
                if(s.insert(p).second){
                    v[i]=p;
                    break;
                }
            }
            osin<<v[i].ff<<" "<<v[i].ss<<"\n";
        }
        osans<<solution(n,v)<<"\n";
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
    int n=10000;
    osin<<n<<"\n";
    vector<pii> v;
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            v.push_back({i,j});
            osin<<v.back().ff<<" "<<v.back().ss<<"\n";
        }
    }
    osans<<solution(n,v)<<"\n";
    osin.close();
    osans.close();
}

void generator_handmade02()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade02.in");
    osans.open(path+"secret/"+"handmade02.ans");
    int n=100000;
    osin<<n<<"\n";
    vector<pii> v;
    for(int i=1; i<=n; i++){
        v.push_back({i,i});
        osin<<v.back().ff<<" "<<v.back().ss<<"\n";
    }
    osans<<solution(n,v)<<"\n";
    osin.close();
    osans.close();
}

int main()
{
    srand((unsigned)time(NULL));
    // generator_random_small(10);
    // generator_random_large(10);
    generator_random_maximum(2);
    generator_handmade01();
    generator_handmade02();
    return 0;
}
