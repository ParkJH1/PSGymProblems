#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    int answer=0;
    for(int i=0; i<n; i++){
        int p=0,c=0;
        for(int j=i; j<n; j++){
            if(s[j]=='P') p+=1;
            if(s[j]=='C') c+=1;
            if(p==m & c==k) answer+=1;
        }
    }
    cout<<answer;
    return 0;
}
