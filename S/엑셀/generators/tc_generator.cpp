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

string int2str(int n)
{
    string ret;
    while(n>0){
        n-=1;
        ret+='A'+n%26;
        n/=26;
    }
    reverse(all(ret));
    return ret;
}

int str2int(string s)
{
    int ret=0;
    for(char c : s){
        ret*=26;
        ret+=c-'A'+1;
    }
    return ret;
}

void generator_random_small(int datacnt)
{
    int data=1;
    set<pii> s;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        int r=myrand(100)+1;
        int c=myrand(100)+1;
        if(!s.insert({r,c}).second) continue;
        if(myrand(2)){
            osin<<int2str(c)<<r<<"\n";
            osans<<"R"<<r<<"C"<<c<<"\n";
        }
        else{
            osin<<"R"<<r<<"C"<<c<<"\n";
            osans<<int2str(c)<<r<<"\n";
        }
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_random_large(int datacnt)
{
    int data=1;
    set<pii> s;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_large"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_large"+zeropad(data,2)+".ans");
        int r=myrand(1000000)+1;
        int c=myrand(1000000)+1;
        if(!s.insert({r,c}).second) continue;
        if(myrand(2)){
            osin<<int2str(c)<<r<<"\n";
            osans<<"R"<<r<<"C"<<c<<"\n";
        }
        else{
            osin<<"R"<<r<<"C"<<c<<"\n";
            osans<<int2str(c)<<r<<"\n";
        }
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_random_special(int datacnt)
{
    int data=1;
    set<pii> s;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_special"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_special"+zeropad(data,2)+".ans");
        int r=myrand(1000000)+1;
        int c=myrand(1000000)+1;
        string str=int2str(c);
        if(str[0]!='R') continue;
        if(!s.insert({r,c}).second) continue;
        if(myrand(2)){
            osin<<int2str(c)<<r<<"\n";
            osans<<"R"<<r<<"C"<<c<<"\n";
        }
        else{
            osin<<"R"<<r<<"C"<<c<<"\n";
            osans<<int2str(c)<<r<<"\n";
        }
        data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    generator_random_small(10);
    generator_random_large(10);
    generator_random_special(5);
    return 0;
}
