#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    int map[n*n+1];
    for(int i=0 ;i<n*n+1; i++){
        map[i]=0;
    }
    for(int i=0 ;i<n; i++){
        for(int j=0 ;j<n; j++){
            int t;
            cin>>t;
            map[t]+=1;
        }
    }
    for(int i=0 ;i<n*n+1; i++){
        if(map[i]>n*n-n){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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