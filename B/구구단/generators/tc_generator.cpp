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

int solution(int a, int b)
{
    return a+b;
}

void generator_allcase()
{
    int data=1;
    while(data<=9){
        if(data!=2){
            ofstream osin,osans;
            osin.open(path+"secret/"+"allcase"+zeropad(data,2)+".in");
            osans.open(path+"secret/"+"allcase"+zeropad(data,2)+".ans");
            osin<<data<<"\n";
            for(int i=1; i<=9; i++) osans<<data<<" x "<<i<<" = "<<data*i<<"\n";
            osin.close();
            osans.close();
        }
        data+=1;
    }
}

int main()
{
    generator_allcase();
    return 0;
}
