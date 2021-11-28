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

string solution(vector<pair<string,pair<char,int>>> v)
{
    int n=v.size();
    map<string,int> m;
    int mx=0;
    for(int i=0; i<n; i++){
        auto it=m.insert({v[i].ff,0}).ff;
        if(v[i].ss.ff=='R') it->ss-=v[i].ss.ss;
        else it->ss+=v[i].ss.ss;
    }
    for(auto it=m.begin(); it!=m.end(); it++) mx=max(mx,it->ss);
    map<string,int> m2;
    for(int i=0; i<n; i++){
        auto it=m2.insert({v[i].ff,0}).ff;
        if(v[i].ss.ff=='R') it->ss-=v[i].ss.ss;
        else it->ss+=v[i].ss.ss;
        if(it->ss>=mx && m[v[i].ff]==mx){
            return it->ff;
        }
    }
    assert(true);
    return "";
}

void generator_random_small(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        int n=myrand(100)+1;
        int m=myrand(n)+1;
        set<string> s;
        vector<string> sss;
        for(int i=0; i<m; i++){
            string str;
            int nn=myrand(19)+2;
            for(int j=0; j<nn; j++) str+='a'+myrand(26);
            if(!s.insert(str).ss) i-=1;
            sss.push_back(str);
        }
        osin<<n<<"\n";
        vector<pair<string,pair<char,int>>> v(n);
        for(int i=0; i<n; i++){
            v[i].ff=sss[myrand(m)];
            if(myrand(2)) v[i].ss.ff='R';
            else v[i].ss.ff='B';
            v[i].ss.ss=myrand(100)+1;
            osin<<v[i].ff<<" "<<v[i].ss.ff<<" "<<v[i].ss.ss<<"\n";
        }
        osans<<solution(v)<<"\n";
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
        int m=myrand(n)+1;
        set<string> s;
        vector<string> sss;
        for(int i=0; i<m; i++){
            string str;
            int nn=myrand(19)+2;
            for(int j=0; j<nn; j++) str+='a'+myrand(26);
            if(!s.insert(str).ss) i-=1;
            sss.push_back(str);
        }
        osin<<n<<"\n";
        vector<pair<string,pair<char,int>>> v(n);
        for(int i=0; i<n; i++){
            v[i].ff=sss[myrand(m)];
            if(myrand(2)) v[i].ss.ff='R';
            else v[i].ss.ff='B';
            v[i].ss.ss=myrand(100)+1;
            osin<<v[i].ff<<" "<<v[i].ss.ff<<" "<<v[i].ss.ss<<"\n";
        }
        osans<<solution(v)<<"\n";
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
        int m=myrand(n)+1;
        set<string> s;
        vector<string> sss;
        for(int i=0; i<m; i++){
            string str;
            int nn=myrand(19)+2;
            for(int j=0; j<nn; j++) str+='a'+myrand(26);
            if(!s.insert(str).ss) i-=1;
            sss.push_back(str);
        }
        osin<<n<<"\n";
        vector<pair<string,pair<char,int>>> v(n);
        for(int i=0; i<n; i++){
            v[i].ff=sss[myrand(m)];
            if(myrand(2)) v[i].ss.ff='R';
            else v[i].ss.ff='B';
            v[i].ss.ss=myrand(100)+1;
            osin<<v[i].ff<<" "<<v[i].ss.ff<<" "<<v[i].ss.ss<<"\n";
        }
        osans<<solution(v)<<"\n";
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
