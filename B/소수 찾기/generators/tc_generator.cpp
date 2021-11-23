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

vector<int> solution(int a, int b)
{
    vector<int> ret;
    for(int i=a; i<=b; i++){
        bool b=true;
        for(int j=2; j<i; j++) if(i%j==0) b=false;
        if(b) ret.push_back(i);
    }
    return ret;
}

void generator_random(int datacnt)
{
    int data=1;
    bool check=false;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random"+zeropad(data,2)+".ans");
        int a=myrand(100)+1;
        int b=myrand(100)+1;
        if(a>b) swap(a,b);
        osin<<a<<" "<<b<<"\n";
        vector<int> answer=solution(a,b);
        if(answer.empty()){
            osans<<"X";
            check=true;
        }
        else for(int ans : answer) osans<<ans<<" ";
        osans<<"\n";
        if(data==datacnt && !check);
        else data+=1;
        osin.close();
        osans.close();
    }
}

void generator_handmade01()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade01.in");
    osans.open(path+"secret/"+"handmade01.ans");
    int a=1;
    int b=100;
    osin<<a<<" "<<b<<"\n";
    vector<int> answer=solution(a,b);
    if(answer.empty()) osans<<"X";
    else for(int ans : answer) osans<<ans<<" ";
    osans<<"\n";
    osin.close();
    osans.close();
}

int main()
{
    generator_random(10);
    generator_handmade01();
    return 0;
}
