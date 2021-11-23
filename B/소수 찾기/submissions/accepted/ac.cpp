#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    bool check=false;
    for(int i=a; i<=b; i++){
        bool p=true;
        for(int j=2; j<i; j++) if(i%j==0) p=false;
        if(p){
            cout<<i<<" ";
            check=true;
        }
    }
    if(!check) cout<<"X";
    return 0;
}
