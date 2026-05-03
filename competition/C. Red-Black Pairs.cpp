#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    string up;
    string down;
    cin>>up;
    cin>>down;

    int dp[n+1];
    dp[0]=0;
    if(up[0]==down[0]){
        dp[1]=0;
    }else{
        dp[1]=1;
    }
    
    for(int i=1; i<n; i++){
        // cout<<(1?up[i]!=down[i]:0)<<endl;
        // cout<<dp[i-1]+(1?up[i]!=up[i-1]:0)+(1?down[i]!=down[i-1]:0 )<<endl;

        dp[i+1]=min(dp[i]+ (1?up[i]!=down[i]:0), dp[i-1]+(1?up[i]!=up[i-1]:0)+(1?down[i]!=down[i-1]:0 ));

    }
    cout<<dp[n]<<endl;

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