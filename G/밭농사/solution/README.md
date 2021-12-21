# 솔루션

모든 구간을 보면서 각 구간에 있는 감자와 당근의 수를 구해서 검사한다.

구간 속에 감자 당근 수를 구할 때 누적합을 사용한다.



# 소스코드

```cpp
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
```
