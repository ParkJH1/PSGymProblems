#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,a;
    cin>>n>>a;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> b(n);
    int answer=0;
    for(int i=0; i<n; i++){
        b[n-1-i]=1;
        do{
            int sum=0;
            for(int j=0; j<n; j++) if(b[j]) sum+=v[j];
            if(sum==a) answer+=1;
        }while(next_permutation(all(b)));
    }
    cout<<answer;
    return 0;
}
