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

ll solution(int n, int a, vector<int> v)
{
    vector<int> b(n);
    int answer=0;
    for(int i=0; i<n; i++){
        b[n-1-i]=1;
        do{
            int sum=0;
            for(int j=0; j<n; j++) if(b[j]) sum+=v[j];
            if(sum==a) answer+=1;
        }while(next_permutation(all(b)));
    }
    return answer;
}

void generator_random(int datacnt)
{
    int data=1;
    int z=0;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random"+zeropad(data,2)+".ans");
        int n=rand()%15+1;
        int k=rand()%100+1;
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i]=rand()%50+1;
        osin<<n<<" "<<k<<"\n";
        for(int i=0; i<n; i++) osin<<v[i]<<" ";
        osin<<"\n";
        ll answer=solution(n,k,v);
        osans<<answer<<"\n";
        if(answer!=0 || (answer==0 && z==0)) data+=1;
        if(answer==0) z=1;
        osin.close();
        osans.close();
    }
}

void generator_handmade01()
{
    ofstream osin,osans;
    osin.open(path+"secret/"+"handmade01.in");
    osans.open(path+"secret/"+"handmade01.ans");
    int n=15;
    int k=7;
    vector<int> v(n);
    for(int i=0; i<n; i++) v[i]=1;
    osin<<n<<" "<<k<<"\n";
    for(int i=0; i<n; i++) osin<<v[i]<<" ";
    osin<<"\n";
    osans<<solution(n,k,v)<<"\n";
    osin.close();
    osans.close();
}

int main()
{
    srand((unsigned)time(NULL));
    generator_random(10);
    generator_handmade01();
    return 0;
}
