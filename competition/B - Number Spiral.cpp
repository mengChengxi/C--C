#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    long long x,y;
    cin>>x>>y;
    if(y>=x){
        if(y%2==1){
            y*=y;
            cout<<y-x+1<<endl;
        }else{
            y=(y-1)*(y-1)+1+x-1;
            cout<<y<<endl;
        }
        
        
    }else{
        if(x%2==0){
            cout<<x*x-y+1<<endl;
        }else{
            cout<<(x-1)*(x-1)+1+y-1<<endl;
        }
    }
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
