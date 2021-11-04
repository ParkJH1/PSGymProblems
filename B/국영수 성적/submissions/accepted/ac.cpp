#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b+c>=90*3) cout<<'A';
    else if(a+b+c>=80*3) cout<<'B';
    else if(a+b+c>=70*3) cout<<'C';
    else if(a+b+c>=60*3) cout<<'D';
    cout<<'F';
    return 0;
}
