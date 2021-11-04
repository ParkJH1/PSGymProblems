# 솔루션

학생들의 몸무게를 전부 보면서 80이상인 개수를 센다.



# 소스코드

```cpp
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
```
