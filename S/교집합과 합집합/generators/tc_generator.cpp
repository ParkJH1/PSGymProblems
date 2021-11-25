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
        set<int> a,b;
        for(int i=0; i<n; i++) if(!a.insert(myrand(1000000000)+1).second) i-=1;
        for(int i=0; i<m; i++) if(!b.insert(myrand(1000000000)+1).second) i-=1;
        for(int aa : a) osin<<aa<<" ";
        osin<<"\n";
        for(int bb : b) osin<<bb<<" ";
        osin<<"\n";
        set<int> s1,s2;
        for(int aa : a){
            if(b.find(aa)!=b.end()) s1.insert(aa);
            s2.insert(aa);
        }
        for(int bb : b) s2.insert(bb);
        if(s1.empty()) osans<<"X";
        else for(int s : s1) osans<<s<<" ";
        osans<<"\n";
        for(int s : s2) osans<<s<<" ";
        osans<<"\n";
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
        int n=myrand(1000000)+1;
        int m=myrand(1000000)+1;
        osin<<n<<" "<<m<<"\n";
        set<int> a,b;
        for(int i=0; i<n; i++) if(!a.insert(myrand(1000000000)+1).second) i-=1;
        for(int i=0; i<m; i++) if(!b.insert(myrand(1000000000)+1).second) i-=1;
        for(int aa : a) osin<<aa<<" ";
        osin<<"\n";
        for(int bb : b) osin<<bb<<" ";
        osin<<"\n";
        set<int> s1,s2;
        for(int aa : a){
            if(b.find(aa)!=b.end()) s1.insert(aa);
            s2.insert(aa);
        }
        for(int bb : b) s2.insert(bb);
        if(s1.empty()) osans<<"X";
        else for(int s : s1) osans<<s<<" ";
        osans<<"\n";
        for(int s : s2) osans<<s<<" ";
        osans<<"\n";
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
        int n=1000000;
        int m=1000000;
        osin<<n<<" "<<m<<"\n";
        set<int> a,b;
        for(int i=0; i<n; i++) if(!a.insert(myrand(1000000000)+1).second) i-=1;
        for(int i=0; i<m; i++) if(!b.insert(myrand(1000000000)+1).second) i-=1;
        for(int aa : a) osin<<aa<<" ";
        osin<<"\n";
        for(int bb : b) osin<<bb<<" ";
        osin<<"\n";
        set<int> s1,s2;
        for(int aa : a){
            if(b.find(aa)!=b.end()) s1.insert(aa);
            s2.insert(aa);
        }
        for(int bb : b) s2.insert(bb);
        if(s1.empty()) osans<<"X";
        else for(int s : s1) osans<<s<<" ";
        osans<<"\n";
        for(int s : s2) osans<<s<<" ";
        osans<<"\n";
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
