#include <iostream>
using namespace std;
int main()
{
    int answer=-9999;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(answer<a) answer=a;
    }
    cout<<answer;
    return 0;
}
