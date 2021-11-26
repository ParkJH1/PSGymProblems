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

deque<int> solution(deque<int> v)
{
    deque<int> ret;
    while(v.size()>1){
        if(v.front()>v.back()){
            ret.push_back(v.back());
            v.pop_back();
        }
        else{
            ret.push_front(v.front());
            v.pop_front();
        }
    }
    ret.push_front(v.front());
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
        osin<<n<<"\n";
        deque<int> v(n);
        for(int i=0; i<n; i++) v[i]=i+1;
        random_shuffle(all(v));
        for(int i=0; i<n; i++) osin<<v[i]<<" ";
        osin<<"\n";
        deque<int> answer=solution(v);
        for(int ans : answer) osans<<ans<<" ";
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
        int n=myrand(100000)+1;
        osin<<n<<"\n";
        deque<int> v(n);
        for(int i=0; i<n; i++) v[i]=i+1;
        random_shuffle(all(v));
        for(int i=0; i<n; i++) osin<<v[i]<<" ";
        osin<<"\n";
        deque<int> answer=solution(v);
        for(int ans : answer) osans<<ans<<" ";
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
        int n=100000;
        osin<<n<<"\n";
        deque<int> v(n);
        for(int i=0; i<n; i++) v[i]=i+1;
        random_shuffle(all(v));
        for(int i=0; i<n; i++) osin<<v[i]<<" ";
        osin<<"\n";
        deque<int> answer=solution(v);
        for(int ans : answer) osans<<ans<<" ";
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
