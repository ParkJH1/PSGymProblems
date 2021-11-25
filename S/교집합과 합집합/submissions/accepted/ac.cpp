#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    set<int> a,b;
    while(n--){
        int aa;
        cin>>aa;
        a.insert(aa);
    }
    while(m--){
        int bb;
        cin>>bb;
        b.insert(bb);
    }
    set<int> s1,s2;
    for(int aa : a){
        if(b.find(aa)!=b.end()) s1.insert(aa);
        s2.insert(aa);
    }
    for(int bb : b) s2.insert(bb);
    if(s1.empty()) cout<<"X";
    else for(int s : s1) cout<<s<<" ";
    cout<<"\n";
    for(int s : s2) cout<<s<<" ";
    return 0;
}
