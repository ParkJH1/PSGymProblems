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

int gcd(int a, int b)
{
    return (a%b==0)?b:gcd(b,a%b);
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
        osin<<a<<" "<<b<<"\n";
        int g=gcd(a,b);
        osans<<g<<" "<<a*b/g<<"\n";
        if(check && g==1);
        else data+=1;
        if(g==1) check=true;
        osin.close();
        osans.close();
    }
}

int main()
{
    generator_random(10);
    return 0;
}
