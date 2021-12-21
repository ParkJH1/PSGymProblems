#include <iostream>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    int answer=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int p=0,c=0;
            for(int kk=i; kk<=j; kk++){
                if(s[kk]=='P') p+=1;
                if(s[kk]=='C') c+=1;
            }
            if(p==m & c==k) answer+=1;
        }
    }
    cout<<answer;
    return 0;
}
