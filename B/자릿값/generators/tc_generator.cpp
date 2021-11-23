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

vector<int> solution(int n)
{
    vector<int> ret;
    int tmp=10000;
    bool check=true;
    while(tmp!=0){
        if(n/tmp!=0) check=false;
        if(!check){
            ret.push_back(n/tmp*tmp);
            n=n-n/tmp*tmp;
        }
        tmp/=10;
    }
    return ret;
}

void generator_random(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random"+zeropad(data,2)+".ans");
        int tc=rand()%10000+1;
        osin<<tc<<"\n";
        while(tc--){
            int n=rand()%10000+1;
            vector<int> answer=solution(n);
            osin<<n<<"\n";
            for(int ans : answer) osans<<ans<<" ";
            osans<<"\n";
        }
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_handmade1()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade01.in");
    osans.open(path+"secret/"+"handmade01.ans");
    int tc=10000;
    osin<<tc<<"\n";
    for(int i=1; i<=tc; i++){
        int n=i;
        vector<int> answer=solution(n);
        osin<<n<<"\n";
        for(int ans : answer) osans<<ans<<" ";
        osans<<"\n";
    }
    osin.close();
    osans.close();
}

void generator_handmade2()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade02.in");
    osans.open(path+"secret/"+"handmade02.ans");
    int tc=10000;
    osin<<tc<<"\n";
    for(int i=1; i<=tc; i++){
        int n=9999;
        vector<int> answer=solution(n);
        osin<<n<<"\n";
        for(int ans : answer) osans<<ans<<" ";
        osans<<"\n";
    }
    osin.close();
    osans.close();
}

void generator_handmade3()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade03.in");
    osans.open(path+"secret/"+"handmade03.ans");
    int tc=10000;
    osin<<tc<<"\n";
    for(int i=1; i<=tc; i++){
        int n=10000;
        vector<int> answer=solution(n);
        osin<<n<<"\n";
        for(int ans : answer) osans<<ans<<" ";
        osans<<"\n";
    }
    osin.close();
    osans.close();
}

int main()
{
    srand((unsigned)time(NULL));
    generator_random(10);
    generator_handmade1();
    generator_handmade2();
    generator_handmade3();
    return 0;
}
