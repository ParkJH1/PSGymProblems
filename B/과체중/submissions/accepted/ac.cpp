#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int answer=0;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(a>=80) answer+=1;
    }
    cout<<answer;
    return 0;
}
