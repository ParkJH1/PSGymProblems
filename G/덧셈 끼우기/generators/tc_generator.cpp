#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>
#include <fstream>
#include <unistd.h>

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

using namespace std;
using pii=pair<int,int>;
using ll=long long;

string path="../data/";

string zeropad(int n, int d)
{
    string ret=to_string(n);
    while(ret.length()<d) ret="0"+ret;
    return ret;
}

ll solution(string s)
{
    int n=s.length();
    vector<int> v(n-1);
    ll answer=0;
    for(int i=0; i<n-1; i++){
        v[n-2-i]=1;
        do{
            ll sum=0;
            ll now=s[0]-'0';
            for(int j=1; j<n; j++){
                if(v[j-1]){
                    sum+=now;
                    now=s[j]-'0';
                }
                else now=now*10+s[j]-'0';
            }
            sum+=now;
            answer+=sum;
        }while(next_permutation(all(v)));
    }
    return answer;
}

void generator_random(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random"+zeropad(data,2)+".ans");
        int n=rand()%8+2;
        string s;
        for(int i=0; i<n; i++) s+=('0'+rand()%9+1);
        osin<<s<<"\n";
        osans<<solution(s)<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_maximum(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"maximum"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"maximum"+zeropad(data,2)+".ans");
        osin<<"999999999"<<"\n";
        osans<<solution("999999999")<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    srand((unsigned)time(NULL));
    generator_random(10);
    generator_maximum(1);
    return 0;
}
