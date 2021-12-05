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
#include <random>
#include <chrono>

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using pii=pair<int,int>;
using ll=long long;

string path="../data/";

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myrand(ll B) {
	return (unsigned long long)rng() % B;
}

string zeropad(int n, int d)
{
    string ret=to_string(n);
    while(ret.length()<d) ret="0"+ret;
    return ret;
}

int solution(vector<vector<vector<int>>> v)
{
    int answer=0;
    set<vector<int>> s;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            s.insert(v[i][j]);
        }
    }
    return s.size();
}

void generator_sample(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"sample/"+"sample"+zeropad(data,2)+".in");
        osans.open(path+"sample/"+"sample"+zeropad(data,2)+".ans");
        int n=3;
        int m=2;
        osin<<n<<" "<<m<<"\n";
        vector<vector<vector<int>>> v(n,vector<vector<int>>(m,vector<int>(3)));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<3; k++){
                    v[i][j][k]=myrand(3);
                    osin<<v[i][j][k]<<" ";
                }
            }
            osin<<"\n";
        }
        osans<<solution(v)<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_random_small(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_small"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_small"+zeropad(data,2)+".ans");
        int n=myrand(10)+1;
        int m=myrand(10)+1;
        osin<<n<<" "<<m<<"\n";
        vector<vector<vector<int>>> v(n,vector<vector<int>>(m,vector<int>(3)));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<3; k++){
                    v[i][j][k]=myrand(5);
                    osin<<v[i][j][k]<<" ";
                }
            }
            osin<<"\n";
        }
        osans<<solution(v)<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_random_large(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_large"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_large"+zeropad(data,2)+".ans");
        int n=myrand(1000)+1;
        int m=myrand(1000)+1;
        osin<<n<<" "<<m<<"\n";
        vector<vector<vector<int>>> v(n,vector<vector<int>>(m,vector<int>(3)));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<3; k++){
                    v[i][j][k]=myrand(256);
                    osin<<v[i][j][k]<<" ";
                }
            }
            osin<<"\n";
        }
        osans<<solution(v)<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

void generator_random_maximum(int datacnt)
{
    int data=1;
    while(data<=datacnt){
        ofstream osin,osans;
        osin.open(path+"secret/"+"random_maximum"+zeropad(data,2)+".in");
        osans.open(path+"secret/"+"random_maximum"+zeropad(data,2)+".ans");
        int n=1000;
        int m=1000;
        osin<<n<<" "<<m<<"\n";
        vector<vector<vector<int>>> v(n,vector<vector<int>>(m,vector<int>(3)));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<3; k++){
                    v[i][j][k]=myrand(256);
                    osin<<v[i][j][k]<<" ";
                }
            }
            osin<<"\n";
        }
        osans<<solution(v)<<"\n";
        data+=1;
        osin.close();
        osans.close();
    }
}

int main()
{
    // generator_sample(1);
    generator_random_small(10);
    generator_random_large(10);
    generator_random_maximum(2);
    return 0;
}
