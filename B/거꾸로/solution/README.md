# 솔루션

문자열을 뒤에서부터 출력한다.

STL reverse 함수를 사용해도 좋다.



# 소스코드

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}
```
