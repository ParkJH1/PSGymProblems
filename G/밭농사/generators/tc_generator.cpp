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

int solution(int n, int m, int k, string s)
{
    int answer=0;
    for(int i=0; i<n; i++){
        int p=0,c=0;
        for(int j=i; j<n; j++){
            if(s[j]=='P') p+=1;
            if(s[j]=='C') c+=1;
            if(p==m & c==k) answer+=1;
        }
    }
    return answer;
}

void generator_random_small(int datacnt)
{
    int data=1;
    bool b=false;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        int n=myrand(50)+1;
        int m=myrand(n)+1;
        int k=myrand(n)+1;
        string s;
        for(int i=0; i<n; i++){
            if(myrand(2)) s+='P';
            else s+='C';
        }
        osin<<n<<" "<<m<<" "<<k<<"\n";
        osin<<s<<"\n";
        int answer=solution(n,m,k,s);
        if(answer==0){
            if(b) continue;
            b=true;
        }
        osans<<answer<<"\n";
        cout<<data<<"==\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_random_large(int datacnt)
{
    int data=1;
    bool b=false;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_large"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_large"+zeropad(data,2)+".ans");
        int n=myrand(5000)+1;
        int m=myrand(n)+1;
        int k=myrand(n)+1;
        string s;
        for(int i=0; i<n; i++){
            if(myrand(2)) s+='P';
            else s+='C';
        }
        osin<<n<<" "<<m<<" "<<k<<"\n";
        osin<<s<<"\n";
        int answer=solution(n,m,k,s);
        if(answer==0){
            if(b) continue;
            b=true;
        }
        osans<<answer<<"\n";
        cout<<data<<"==\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_random_maximum(int datacnt)
{
    int data=1;
    bool b=false;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_maximum"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_maximum"+zeropad(data,2)+".ans");
        int n=5000;
        int m=myrand(n)+1;
        int k=myrand(n)+1;
        string s;
        for(int i=0; i<n; i++){
            if(myrand(2)) s+='P';
            else s+='C';
        }
        osin<<n<<" "<<m<<" "<<k<<"\n";
        osin<<s<<"\n";
        int answer=solution(n,m,k,s);
        if(answer==0){
            if(b) continue;
            b=true;
        }
        osans<<answer<<"\n";
        cout<<data<<"==\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_handmade01()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade01.in");
    osans.open(path+"secret/"+"handmade01.ans");
    int n=5000;
    int m=2;
    int k=0;
    string s;
    for(int i=0; i<n; i++){
        s+='P';
    }
    osin<<n<<" "<<m<<" "<<k<<"\n";
    osin<<s<<"\n";
    int answer=solution(n,m,k,s);
    osans<<answer<<"\n";
    osin.close();
    osans.close();
}

void generator_handmade02()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade02.in");
    osans.open(path+"secret/"+"handmade02.ans");
    int n=5000;
    int m=2;
    int k=2;
    string s;
    for(int i=0; i<n; i++){
        if(i%2) s+='P';
        else s+='C';
    }
    osin<<n<<" "<<m<<" "<<k<<"\n";
    osin<<s<<"\n";
    int answer=solution(n,m,k,s);
    osans<<answer<<"\n";
    osin.close();
    osans.close();
}

int main()
{
    generator_random_small(10);
    // generator_random_large(10);
    generator_random_maximum(2);
    generator_handmade01();
    generator_handmade02();
    return 0;
}
