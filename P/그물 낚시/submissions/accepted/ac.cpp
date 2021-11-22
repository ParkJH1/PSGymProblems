#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<pair<int,int>> s;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        for(int j=-1; j<=1; j++){
            for(int k=-1; k<=1; k++){
                s.insert({x+j,y+k});
            }
        }
    }
    cout<<s.size();
    return 0;
}
