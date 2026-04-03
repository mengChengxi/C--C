#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    int charis[n+1];
    for(int i=0;i<n+1; i++){
        charis[i]=0;
    }
    int maxn=0;
    int current=0;
    for(int i=1; i<n+1;i++){
        if(charis[i]!=1){
            current++;
            maxn=max(current,maxn);
        }
        int t;
        cin>>t;
        charis[t]=1;
    }
    cout<<maxn<<endl;
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