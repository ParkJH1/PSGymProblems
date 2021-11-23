#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%400==0 || (n%100!=0 && n%4==0)) cout<<"LEAP\n";
        else cout<<"COMMON\n";
    }
    return 0;
}
