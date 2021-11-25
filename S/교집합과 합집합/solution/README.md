# 솔루션

두 집합에 전부 있는 수들은 교집합으로, 두 집합 중 하나라도 있는 수들은 합집합으로 모아서 출력한다.

STL set 자료구조를 활용하면 구현하기 편리하다.

추가로 교집합, 합집합을 구해주는 STL 함수도 있다.



# 소스코드

```cpp
#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    set<int> a,b;
    while(n--){
        int aa;
        cin>>aa;
        a.insert(aa);
    }
    while(m--){
        int bb;
        cin>>bb;
        b.insert(bb);
    }
    set<int> s1,s2;
    for(int aa : a){
        if(b.find(aa)!=b.end()) s1.insert(aa);
        s2.insert(aa);
    }
    for(int bb : b) s2.insert(bb);
    if(s1.empty()) cout<<"X";
    else for(int s : s1) cout<<s<<" ";
    cout<<"\n";
    for(int s : s2) cout<<s<<" ";
    return 0;
}
```
