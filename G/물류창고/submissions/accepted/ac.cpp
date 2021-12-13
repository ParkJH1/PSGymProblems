#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v1,v2;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        if(a==1) v1.push_back(b);
        else v2.push_back(b);
    }
    int answer=0;
    int now=0;
    int cnt=0;
    sort(v1.rbegin(),v1.rend());
    sort(v2.rbegin(),v2.rend());
    int i=0,j=0;
    for(; i<v2.size(); i++){
        if(cnt+2>m) break;
        now+=v2[i];
        cnt+=2;
    }
    for(; j<v1.size(); j++){
        if(cnt+1>m) break;
        now+=v1[j];
        cnt+=1;
    }
    answer=now;
    while(i--){
        now-=v2[i];
        cnt-=2;
        for(; j<v1.size(); j++){
            if(cnt+1>m) break;
            now+=v1[j];
            cnt+=1;
        }
        answer=max(answer,now);
    }
    cout<<answer;
    return 0;
}
