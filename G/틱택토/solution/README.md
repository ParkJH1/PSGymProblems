# 솔루션

완전탐색

틱택토 판의 경우의 수는 3^9=19683가지기 때문에 모든 경우를 보는 방법을 충분히 사용할 수 있다.

상태에 대한 처리를 편하게 하기 위해서는 두 플레이어의 착수 과정을 직접 시뮬레이션 하면서 중간 결과를 기록해나가면 정상적인 플레이로 만들 수 있는 경우의 수를 모두 기록할 수 있다.

입력받은 게임판의 상태가 기록된 게임판의 모습 중에 없다면 비정상적으로 진행된 경기다.



# 소스코드

```cpp
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
#define rall(a) a.rbegin(),a.rend()

using namespace std;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

pii operator+(pii a, pii b)
{
    return {a.ff+b.ff,a.ss+b.ss};
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

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);

    vector<string> answer={"B", "A", "F", "D", "C", "E"};

    map<string,int> m;
    string v(9,'.');
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            dfs(m,v,'O',i,j);
        }
    }
    string s;
    for(int i=0; i<3; i++){
        string t;
        cin>>t;
        s+=t;
    }

    if(m.find(s)==m.end()) cout<<"F";
    else cout<<answer[m[s]];

    return 0;
}
```
