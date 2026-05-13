#include <bits/stdc++.h>
#include <future>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> table(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tt;
            cin>>tt;

            table[i][j]=tt;
        }
    }

    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(m));

    dp[0][0]={table[0][0],-table[0][0]};
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0&&j==0)continue;
            if(i>0&&j>0){
                dp[i][j]={(max(dp[i-1][j].first,dp[i][j-1].first)+table[i][j]),
                    min(min(max(dp[i-1][j].second,dp[i][j-1].first)+table[i][j],
                        max(dp[i-1][j].first,dp[i][j-1].second)+table[i][j]),
                        (max(dp[i-1][j].first,dp[i][j-1].first)-table[i][j]))};
                continue;
            }
            if(i>0&&j==0){
                dp[i][j]={dp[i-1][j].first+table[i][j],
                    min(dp[i-1][j].second+table[i][j],dp[i-1][j].first-table[i][j])};
                continue;
            }
            if(i==0&&j>0){
                dp[i][j]={dp[i][j-1].first+table[i][j],
                    min(dp[i][j-1].second+table[i][j],dp[i][j-1].first-table[i][j])};
            }


        }
    }

    cout<<dp[n-1][m-1].second<<endl;



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