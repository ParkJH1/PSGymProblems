# 솔루션

바다의 크기가 너무 크기 때문에 배열을 만들어서 구하는 방식은 사용할 수 없다.

물고기가 살고 있는 칸을 중심으로 한 3 x 3 영역에 던진 그물에만 물고기가 잡힌다.

따라서 각 물고기의 위치를 중심으로 한 3 x 3 영역의 칸들을 세주면 된다.

이때, 중복 칸이 있을 수 있으니 set을 이용해서 제거해주면 편리하다.



# 소스코드

```cpp
#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<pair<int,int>> s;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        for(int j=-1; j<=1; j++){
            for(int k=-1; k<=1; k++){
                s.insert({x+j,y+k});
            }
        }
    }
    cout<<s.size();
    return 0;
}
```
