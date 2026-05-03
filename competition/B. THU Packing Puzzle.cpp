#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    long long t,h,u;
    cin>>t>>h>>u;
    long long n=0;
    if(u>=t){
        n+=t*4;
        n+=(u-t)*3+h*3;
    }else{
        n+=u*4;
        t=t-u;
        long long time=min((t)/2,h);
        
        t-=2*time;
        h-=time;
        n+=7*time;
        
        if(h==0){
            if(t!=0){
                n+=t*2+1;
            }
            
        }else{
            if(t==0){
                n+=3*h;
            }else if(t==1){
                n+=2+3*h;
            }
        }
        
    }
    cout<<n<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dashabi;
    cin >> dashabi;
    while (dashabi--) {
        solve();
    }
    return 0;
}