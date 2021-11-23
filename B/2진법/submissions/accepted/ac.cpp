#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    while(n>0){
        s+='0'+n%2;
        n/=2;
    }
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}
