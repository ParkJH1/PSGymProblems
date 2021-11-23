#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mx=-9999,mn=9999;
    while(n--){
        int a;
        cin>>a;
        if(mx<a) mx=a;
        if(mn>a) mn=a;
    }
    cout<<mx<<" "<<mn;
    return 0;
}
