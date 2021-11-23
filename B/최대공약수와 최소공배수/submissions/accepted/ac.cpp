#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return (a%b==0)?b:gcd(b,a%b);
}

int main()
{
    int a,b;
    cin>>a>>b;
    int g=gcd(a,b);
    cout<<g<<" "<<a*b/g;
    return 0;
}
