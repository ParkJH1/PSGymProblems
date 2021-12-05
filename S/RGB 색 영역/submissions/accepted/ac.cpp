#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    set<vector<int>> s;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vector<int> v(3);
            for(int k=0; k<3; k++) cin>>v[k];
            s.insert(v);
        }
    }
    cout<<s.size();
    return 0;
}
