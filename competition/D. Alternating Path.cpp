#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

vector<vector<int>> g;
vector<int> ifdone;
int onec=0;
int zeroc=0;
int beautiful=0;


int dfs(int v,int pc){
    if(ifdone[v]!=-1){
        if(pc!=ifdone[v]){
            return 1;
        }else{
            return 0;
        }
    }
    if(pc==1){
        ifdone[v]=0;
        zeroc++;
    }else{
        ifdone[v]=1;
        onec++;
    }
    int fail=1;
    for(int i=0; i<g[v].size(); i++){
        if(dfs(g[v][i],1-pc)==0){
            fail=0;
        }
    }
    return fail;
    

}   

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> lg(n+1);
    vector<int> lifdone(n+1,-1);
    g=lg;
    ifdone=lifdone;
    while(m--){
        int from,to;

        cin>>from>>to;
        g[from].push_back(to);
        g[to].push_back(from);
        
    }

    beautiful=0;
    for(int i=1; i<n+1; i++){
        if(ifdone[i]==-1){
            zeroc=0;
            onec=0;
            if(dfs(i,0)==1){
                beautiful+=max(zeroc,onec);
            }
        }
    }

    cout<<beautiful<<endl;


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