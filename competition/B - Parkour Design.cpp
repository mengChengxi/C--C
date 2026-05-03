#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int x,y;
    cin>>x>>y;
    // 2,1
    // 3,0
    // 4,-1
    // 2,-2
    if((x+y)%3==0&& y<=x/2.0 && y>=(-x)/4.0){
        cout<<"YES"<<endl;

    }else{
        cout<<"NO"<<endl;
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