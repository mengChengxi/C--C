#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    for(int i=1; i<=n/2; i++){
        for(int j=0; j<n; j++){
            cout<<j+1<<" "<<(j+i)%n+1<<endl;
            fflush(stdout);
            int r;
            cin>>r;
            if(r==1){
                return;
            }
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