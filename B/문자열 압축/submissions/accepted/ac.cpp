#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cnt=1;
    for(int i=1; i<=s.length(); i++){
        if(i==s.length() || s[i]!=s[i-1]){
            if(cnt>=5) cout<<s[i-1]<<"("<<cnt<<")";
            else for(int j=0; j<cnt; j++) cout<<s[i-1];
            cnt=1;
        }
        else cnt+=1;
    }
    return 0;
}
