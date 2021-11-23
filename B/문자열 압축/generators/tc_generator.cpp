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

string solution(string s)
{
    string ret;
    int cnt=1;
    for(int i=1; i<=s.length(); i++){
        if(i==s.length() || s[i]!=s[i-1]){
            if(cnt>=5) ret=ret+s[i-1]+"("+to_string(cnt)+")";
            else for(int j=0; j<cnt; j++) ret+=s[i-1];
            cnt=1;
        }
        else cnt+=1;
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
        int n=myrand(100)+1;
        string s;
        for(int i=0; i<n; i++){
            if(s.empty()) s+='A'+myrand(26);
            else if(myrand(3)<=1) s+=s.back();
            else s+='A'+myrand(26);
        }
        osin<<s<<"\n";
        osans<<solution(s)<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    generator_random(10);
    return 0;
}
