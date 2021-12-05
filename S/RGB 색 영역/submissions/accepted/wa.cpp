#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> v(256*256*256);
    int answer=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a,b,c;
            cin>>a>>b>>c;
            if(!v[a*b*c]){
                answer+=1;
                v[a*b*c]=true;
            }
        }
    }
    cout<<answer;
    return 0;
}
