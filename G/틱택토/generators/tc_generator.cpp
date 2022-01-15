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

vector<string> answer={"B", "A", "F", "D", "C", "E"};
map<string,int> m;
string v(9,'.');

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

bool f(string &v, char c)
{
    for(int i=0; i<3; i++){
        if(v[3*i]==c && v[3*i+1]==c && v[3*i+2]==c) return true;
        if(v[i]==c && v[3+i]==c && v[6+i]==c) return true;
    }
    if(v[0]==c && v[4]==c && v[8]==c) return true;
    if(v[2]==c && v[4]==c && v[6]==c) return true;
    return false;
}

void dfs(map<string,int> &m, string &v, char now, int y, int x)
{
    v[3*y+x]=now;
    if(f(v,now)){
        if(now=='X') m.insert({v,3});
        else m.insert({v,4});
        v[3*y+x]='.';
        return;
    }
    bool b=true;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(v[3*i+j]!='.') continue;
            b=false;
            if(now=='X') dfs(m,v,'O',i,j);
            else dfs(m,v,'X',i,j);
        }
    }
    if(b) m.insert({v,5});
    else if(now=='X') m.insert({v,1});
    else m.insert({v,0});
    v[3*y+x]='.';
}

int solution(int a, int b)
{
    return a+b;
}

void generator_random(int datacnt)
{
    int data=1;
    int cnt[6]={0};
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random"+zeropad(data,2)+".ans");
        string s;
        for(int i=0; i<9; i++){
            int tmp=myrand(3);
            if(tmp==0) s+='.';
            else if(tmp==1) s+='O';
            else s+='X';
            osin<<s[i];
            if(i%3==2) osin<<"\n";
        }
        bool b=true;
        if(m.find(s)==m.end()){
            osans<<"F\n";
            if(cnt[5]==5) b=false;
            else cnt[5]+=1;
        }
        else{
            osans<<answer[m[s]]<<"\n";
            if(cnt[answer[m[s]][0]-'A']==5) b=false;
            else cnt[answer[m[s]][0]-'A']+=1;
        }
        if(b) data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            dfs(m,v,'O',i,j);
        }
    }
    // string s;
    // for(int i=0; i<3; i++){
    //     string t;
    //     cin>>t;
    //     s+=t;
    // }

    // if(m.find(s)==m.end()) cout<<"F";
    // else cout<<answer[m[s]];
    
    generator_random(30);
    return 0;
}
