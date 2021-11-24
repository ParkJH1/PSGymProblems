#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,string>> v(n);
    for(int i=0; i<n; i++) cin>>v[i].second>>v[i].first;
    sort(v.rbegin(),v.rend());
    for(int i=0; i<3; i++) cout<<v[i].second<<"\n";
    return 0;
}
