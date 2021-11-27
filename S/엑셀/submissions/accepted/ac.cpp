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
