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
#include <random>

#define ff first
#define ss second
#define all(a) a.begin(),a.end()

using namespace std;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

pii operator+(pii a, pii b)
{
    return {a.ff+b.ff,a.ss+b.ss};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<pair<string,int>> v(n);
    map<string,int> m;
    int mx=0;
    for(int i=0; i<n; i++){
        cin>>v[i].ff>>v[i].ss;
        auto it=m.insert({v[i].ff,0}).ff;
        it->ss+=v[i].ss;
    }
    for(auto it=m.begin(); it!=m.end(); it++) mx=max(mx,it->ss);
    map<string,int> m2;
    for(int i=0; i<n; i++){
        auto it=m2.insert({v[i].ff,0}).ff;
        it->ss+=v[i].ss;
        if(it->ss>=mx && m[v[i].ff]==mx){
            cout<<it->ff;
            break;
        }
    }
    return 0;
}