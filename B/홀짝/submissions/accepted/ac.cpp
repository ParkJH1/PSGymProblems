#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==1) cout<<"Odd\n";
        else cout<<"Even\n";
    }
    return 0;
}
