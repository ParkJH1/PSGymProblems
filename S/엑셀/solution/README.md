# 솔루션

알파벳과 숫자로 구분해서 문자열을 쪼갠다.

쪼개진 조각의 수로 1번 방식인지 2번 방식인지 확인한 후, 행 번호와 열 번호를 추출한다.

숫자를 알파벳으로 변환하고, 알파벳은 숫자로 변환해서 적절하게 출력해준다.

숫자를 알파벳으로 변환하는 방법은 1부터 26이 A ~ Z로 변환되기 때문에 각 자리를 1씩 빼고 26으로 나눈 나머지를 활용하면 변환이 편리하다.

알파벳을 숫자로 변환하는 방법은 높은 자리 알파벳부터 보면서 결과값에 26을 곱하고 1 ~ 26 숫자로 바꾼 값을 더하는 것을 반복한다.



# 소스코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f(char c)
{
    return c>='A' && c<='Z';
}

string int2str(int n)
{
    string ret;
    while(n>0){
        n-=1;
        ret+='A'+n%26;
        n/=26;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int str2int(string s)
{
    int ret=0;
    for(char c : s){
        ret*=26;
        ret+=c-'A'+1;
    }
    return ret;
}

int main()
{
    string s;
    cin>>s;
    vector<string> v;
    for(char c : s){
        if(v.empty() || f(v.back().back()) != f(c)) v.push_back(string(1,c));
        else v.back().push_back(c);
    }
    if(v.size()==4){
        int r=stoi(v[1]);
        int c=stoi(v[3]);
        cout<<int2str(c)<<r<<"\n";
    }
    else{
        int r=stoi(v[1]);
        cout<<"R"<<r<<"C"<<str2int(v[0])<<"\n";
    }
    return 0;
}
```
