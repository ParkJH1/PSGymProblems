#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n;
    cin>>n;
    deque<int> a(n),b;
    for(int i=0; i<n; i++) cin>>a[i];
    while(a.size()>1){
        if(a.front()>a.back()){
            b.push_back(a.back());
            a.pop_back();
        }
        else{
            b.push_front(a.front());
            a.pop_front();
        }
    }
    b.push_front(a.front());
    for(int bb : b) cout<<bb<<" ";
    return 0;
}
