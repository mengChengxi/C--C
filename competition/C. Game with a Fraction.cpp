#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    long long p, q;
    cin>>p>>q;

    if(p>=q){
        cout<<"Alice"<<endl;
        return;
    }
    if((q*2.0)/3>p){
        cout<<"Alice"<<endl;
        return;
    }
    cout<<"Bob"<<endl;
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