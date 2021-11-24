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

vector<string> solution(vector<pair<int,string>> v)
{
    sort(rall(v));
    vector<string> ret;
    for(int i=0; i<3; i++) ret.push_back(v[i].ss);
    return ret;
}

void generator_random_small(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        int n=myrand(100)+3;
        osin<<n<<"\n";
        vector<pair<int,string>> v(n);
        set<int> s;
        set<string> s2;
        for(int i=0; i<n; i++){
            v[i].ff=myrand(1000000000)+1;
            if(!s.insert(v[i].ff).second){
                i-=1;
                continue;
            }
            int sn=myrand(10)+1;
            v[i].ss.clear();
            for(int j=0; j<sn; j++){
                if(myrand(2)) v[i].ss+='A'+myrand(26);
                else v[i].ss+='a'+myrand(26);
            }
            if(!s2.insert(v[i].ss).second){
                i-=1;
                continue;
            }
            osin<<v[i].ss<<" "<<v[i].ff<<"\n";
        }
        vector<string> answer=solution(v);
        for(int i=0; i<3; i++){
            osans<<answer[i]<<"\n";
        }
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
        int n=myrand(999998)+3;
        osin<<n<<"\n";
        vector<pair<int,string>> v(n);
        set<int> s;
        set<string> s2;
        for(int i=0; i<n; i++){
            v[i].ff=myrand(1000000000)+1;
            if(!s.insert(v[i].ff).second){
                i-=1;
                continue;
            }
            int sn=myrand(10)+1;
            v[i].ss.clear();
            for(int j=0; j<sn; j++){
                if(myrand(2)) v[i].ss+='A'+myrand(26);
                else v[i].ss+='a'+myrand(26);
            }
            if(!s2.insert(v[i].ss).second){
                i-=1;
                continue;
            }
            osin<<v[i].ss<<" "<<v[i].ff<<"\n";
        }
        vector<string> answer=solution(v);
        for(int i=0; i<3; i++){
            osans<<answer[i]<<"\n";
        }
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
        osin<<n<<"\n";
        vector<pair<int,string>> v(n);
        set<int> s;
        set<string> s2;
        for(int i=0; i<n; i++){
            v[i].ff=myrand(1000000000)+1;
            if(!s.insert(v[i].ff).second){
                i-=1;
                continue;
            }
            int sn=myrand(10)+1;
            v[i].ss.clear();
            for(int j=0; j<sn; j++){
                if(myrand(2)) v[i].ss+='A'+myrand(26);
                else v[i].ss+='a'+myrand(26);
            }
            if(!s2.insert(v[i].ss).second){
                i-=1;
                continue;
            }
            osin<<v[i].ss<<" "<<v[i].ff<<"\n";
        }
        vector<string> answer=solution(v);
        for(int i=0; i<3; i++){
            osans<<answer[i]<<"\n";
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
    generator_random_maximum(2);
    return 0;
}
