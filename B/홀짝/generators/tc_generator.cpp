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

string solution(int a)
{
    return (a%2)?"Odd":"Even";
}

void generator_random(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random"+zeropad(data,2)+".ans");
        int t=rand()%10+1;
        osin<<t<<"\n";
        for(int tt=1; tt<=t; tt++){
            int a=rand()%100+1;
            osin<<a<<"\n";
            osans<<solution(a)<<"\n";
        }
        data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    srand((unsigned)time(NULL));
    generator_random(10);
    return 0;
}
