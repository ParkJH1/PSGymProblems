#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    deque<int> v[2];
    deque<int> u[2];
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b);
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    int answer=0;
    int now=0;
    int cnt=0;
    while(true){
        if(cnt+2>m) break;
        now+=v[1].back();
        u[1].push_back(v[1].back());
        v[1].pop_back();
        cnt+=2;
    }
    while(true){
        if(cnt+1>m) break;
        now+=v[0].back();
        u[0].push_back(v[0].back());
        v[0].pop_back();
        cnt+=1;
    }
    answer=now;
    while(true){
        if(u[1].empty() || v[0].empty()) break;
        now-=u[1].back();
        u[1].pop_back();
        now+=v[0].back();
        v[0].pop_back();
        now+=v[0].back();
        v[0].pop_back();
        answer=max(answer,now);
    }
    cout<<answer;
    return 0;
}
