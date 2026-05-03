#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int x,y;
    cin>>x>>y;
    long long k=0;
    for(int i=0; i<16; i++){
        if((x>>i&1)==1&&(x>>i&1)==1){
            k+=(1<<i);
            x+=(1<<i);
            y+=(1<<i);
            cout<<3<<endl;
        }
        if(k>=1e18){
            cout<<-1<<endl;
            return;
        }
        
    }
    cout<<k<<endl;

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