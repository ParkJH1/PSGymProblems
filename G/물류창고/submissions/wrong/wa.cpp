#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].second>>v[i].first;
    }
    sort(v.rbegin(),v.rend());
    int cnt=0;
    int answer=0;
    for(int i=0; i<n; i++){
        if(cnt+v[i].second>m) break;
        answer+=v[i].first;
        cnt+=v[i].second;
    }
    cout<<answer;
    return 0;
}
