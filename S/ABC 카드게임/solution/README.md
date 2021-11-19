# 솔루션

문제에서 주어진 규칙대로 시뮬레이션 한다.

vector의 back, pop_back을 활용하면 구현이 편하다.



# 소스코드

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> v(3);
    cin>>v[0]>>v[1]>>v[2];
    int now=0;
    while(true){
        if(v[now].empty()) break;
        int nxt=v[now].back()-'A';
        v[now].pop_back();
        now=nxt;
    }
    cout<<now+1;
    return 0;
}
```
