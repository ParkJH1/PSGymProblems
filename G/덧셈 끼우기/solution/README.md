# 솔루션

덧셈을 끼워넣는 자리가 최대 8곳 뿐이기 때문에 완전탐색으로 모든 식을 만들어 볼 수 있다.



# 소스코드

```cpp
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
```
