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

char solution(int a, int b, int c)
{
    if(a+b+c>=90*3) return 'A';
    else if(a+b+c>=80*3) return 'B';
    else if(a+b+c>=70*3) return 'C';
    else if(a+b+c>=60*3) return 'D';
    return 'F';
}

void generator_random(int datacnt)
{
    int data=1;
    int d=0,f=0,cc=0;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random"+zeropad(data,2)+".ans");
        int a=rand()%101;
        int b=rand()%101;
        int c=rand()%101;
        osin<<a<<" "<<b<<" "<<c<<"\n";
        char answer=solution(a,b,c);
        if(answer=='F') f+=1;
        if(answer=='D') d+=1;
        if(answer=='C') cc+=1;
        osans<<answer<<"\n";
        if((f<=2 && d<=2 && cc<=2) || (answer!='F' && answer!='D' && answer!='C')) data+=1;
        osin.close();
        osans.close();
    }
}

void test()
{
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            for(int k=0; k<=100; k++){
                float a=i+j+k;
                double b=i+j+k;
                int c=i+j+k;
                float aa=a/3;
                double bb=b/3;
                int cc=c/3;

                char aaa='A';
                if(aa>=90) aaa='A';
                else if(aa>=80) aaa='B';
                else if(aa>=70) aaa='C';
                else if(aa>=60) aaa='D';
                else aaa='F';

                char bbb='A';
                if(bb>=90) bbb='A';
                else if(bb>=80) bbb='B';
                else if(bb>=70) bbb='C';
                else if(bb>=60) bbb='D';
                else bbb='F';

                char ccc='A';
                if(cc>=90) ccc='A';
                else if(cc>=80) ccc='B';
                else if(cc>=70) ccc='C';
                else if(cc>=60) ccc='D';
                else ccc='F';

                if(aaa==bbb && bbb==ccc);
                else{
                    cout<<"========================\n";
                    cout<<aaa<<" "<<bbb<<" "<<ccc<<"\n";
                    cout<<i<<" "<<j<<" "<<k<<"\n";
                    cout<<aa<<" "<<bb<<" "<<cc<<"\n";
                    cout<<"========================\n";
                }
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    generator_random(10);
    // test();
    return 0;
}
