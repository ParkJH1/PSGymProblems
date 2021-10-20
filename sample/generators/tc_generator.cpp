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
#include <fstream>

#define ff first
#define ss second

using namespace std;
using pii=pair<int,int>;
using ll=long long;

int f(int n, int m, int c, vector<pii> v)
{
    for(pii p : v){
        int a=p.ff,b=p.ss;
        if(a==c) c=b;
        else if(b==c) c=a;
    }
    return c;
}

string zeropad(int n)
{
    string ret=to_string(n);
    while(ret.length()<2) ret="0"+ret;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    string path="/Users/pjh/Documents/KMU Problem Solving Club/문제/야바위/testcases/";

    srand((unsigned)time(NULL));
    int tc=50;
    for(int i=1; i<=tc; i++){
        ofstream os1,os2;
        os1.open(path+"tc"+zeropad(i)+".in.txt");
        os2.open(path+"tc"+zeropad(i)+".out.txt");
        int n=rand()%9+2;
        int m=rand()%100+1;
        int c=rand()%n+1;
        os1<<n<<" "<<m<<" "<<c<<"\n";
        vector<pii> v;
        while(m--){
            int a=rand()%n+1;
            int b=rand()%n+1;
            while(a==b){
                b=rand()%n+1;
            }
            v.push_back({a,b});
            os1<<a<<" "<<b<<"\n";
        }
        int answer=f(n,m,c,v);
        os2<<answer<<"\n";
    }
    
    return 0;
}
