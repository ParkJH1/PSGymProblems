#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    vector<int> p(n),c(n);
    if(s[0]=='P') p[0]=1;
    if(s[0]=='C') c[0]=1;
    for(int i=1; i<n; i++){
        p[i]=p[i-1];
        c[i]=c[i-1];
        if(s[i]=='P') p[i]+=1;
        if(s[i]=='C') c[i]+=1;
    }
    int answer=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int pp=p[j],cc=c[j];
            if(i>0){
                pp-=p[i-1];
                cc-=c[i-1];
            }
            if(pp==m & cc==k) answer+=1;
        }
    }
    cout<<answer;
    return 0;
}
