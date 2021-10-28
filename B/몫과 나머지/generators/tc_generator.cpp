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

vector<int> solution(int a, int b)
{
    vector<int> answer(2);
    answer[0]=a/b;
    answer[1]=a%b;
    return answer;
}

void generator_random(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random"+zeropad(data,2)+".ans");
        int a=rand()%100+1;
        int b=rand()%100+1;
        osin<<a<<" "<<b<<"\n";
        vector<int> answer=solution(a,b);
        osans<<answer[0]<<" "<<answer[1]<<"\n";
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
