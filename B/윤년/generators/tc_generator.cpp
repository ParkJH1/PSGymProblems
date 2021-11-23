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

string solution(int n)
{
    if(n%400==0 || (n%100!=0 && n%4==0)) return "LEAP";
    return "COMMON";
}

void generator_random(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random"+zeropad(data,2)+".ans");
        int t=myrand(10)+1;
        osin<<t<<"\n";
        bool b=false;
        while(t--){
            int n=myrand(9000)+1000;
            if(t==0 && !b) n=(myrand(22)+3)*400;
            osin<<n<<"\n";
            string answer=solution(n);
            osans<<answer<<"\n";
            if(answer=="LEAP") b=true;
        }
        data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    srand((unsigned)time(NULL));
    generator_random(10);
    return 0;
}
