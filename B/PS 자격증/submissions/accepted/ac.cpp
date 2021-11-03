#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a+b>=150) cout<<"PASS\n";
        else cout<<"FAIL\n";
    }
    return 0;
}
