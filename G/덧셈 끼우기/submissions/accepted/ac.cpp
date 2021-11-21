#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    vector<int> v(n-1);
    int answer=0;
    for(int i=0; i<n-1; i++){
        v[n-2-i]=1;
        do{
            int sum=0;
            int now=s[0]-'0';
            for(int j=1; j<n; j++){
                if(v[j-1]){
                    sum+=now;
                    now=s[j]-'0';
                }
                else now=now*10+s[j]-'0';
            }
            answer+=sum+now;
        }while(next_permutation(v.begin(),v.end()));
    }
    cout<<answer;
    return 0;
}
