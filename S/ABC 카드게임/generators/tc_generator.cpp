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

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

using namespace std;
using pii=pair<int,int>;
using ll=long long;

string path="../data/";

string zeropad(int n, int d)
{
    string ret=to_string(n);
    while(ret.length()<d) ret="0"+ret;
    return ret;
}

int solution(vector<string> v)
{
    int now=0;
    while(true){
        if(v[now].empty()) return now+1;
        int nxt=v[now].back()-'A';
        v[now].pop_back();
        now=nxt;
    }
    return 0;
}

void generator_random_small(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        vector<string> v(3);
        for(int i=0; i<3; i++){
            int n=rand()%10+1;
            for(int j=0; j<n; j++) v[i]+='A'+rand()%3;
            osin<<v[i]<<"\n";
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
        vector<string> v(3);
        for(int i=0; i<3; i++){
            int n=rand()%100+1;
            for(int j=0; j<n; j++) v[i]+='A'+rand()%3;
            osin<<v[i]<<"\n";
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
        vector<string> v(3);
        for(int i=0; i<3; i++){
            int n=100;
            for(int j=0; j<n; j++) v[i]+='A'+rand()%3;
            osin<<v[i]<<"\n";
        }
        osans<<solution(v)<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    srand((unsigned)time(NULL));
    generator_random_small(10);
    generator_random_large(10);
    generator_random_maximum(2);
    return 0;
}
