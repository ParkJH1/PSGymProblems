# 솔루션

현재까지 처리한 값 중 최대값, 최소값을 저장하는 변수를 만들어두고 배열의 값들을 하나씩 보면서 최대값보다 큰 값이 등장하면 갱신, 최소값보다 작은 값이 등장하면 갱신한다.

최대값, 최소값의 초기값은 문제에서 등장가능한 가장 작은 수보다 작은 값, 가장 큰 수보다 큰 값인 -9999, 9999 같은 값으로 설정해두면 코딩이 편하다.

또는 STL에 max_elements, min_elements 함수를 활용하면 미리 구현된 기능을 사용할 수 있다.



# 소스코드

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mx=-9999,mn=9999;
    while(n--){
        int a;
        cin>>a;
        if(mx<a) mx=a;
        if(mn>a) mn=a;
    }
    cout<<mx<<" "<<mn;
    return 0;
}
```
