#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int tmp=10000;
        bool check=true;
        while(tmp!=0){
            if(n/tmp!=0) check=false;
            if(!check){
                cout<<n/tmp*tmp<<" ";
                n=n-n/tmp*tmp;
            }
            tmp/=10;
        }
        cout<<"\n";
    }

    return 0;
}
