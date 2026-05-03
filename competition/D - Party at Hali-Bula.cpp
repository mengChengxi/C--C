
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

vector<vector<int>> mp;

vector<vector<int>> dp;
int re=0;
void solve() {
    re=0;
    vector<vector<int>> tdp(mp.size()+1,vector<int>(2,-1));
    dp=tdp;


}

int dfs(int i,int iif){
    //0 == self is  
    //1 == self isnot

    if(dp[i][iif]!=-1){
        
    }else if(mp[i].size()==0){
        dp[i][0]=1;
        dp[i][1]=0;
        
    }else if(mp[i].size()==1){
        dp[i][0]=dfs(mp[i][0],1)+1;
        if(dfs(mp[i][0],0)==dfs(mp[i][0],1)){
            re=1;
            dp[i][1]=dfs(mp[i][0],0);
        }else{
            dp[i][1]=max(dfs(mp[i][0],0),dfs(mp[i][0],1));
        }
    }else{
        if(iif==0){
            if(dfs(mp[i][0],1)==dfs(mp[i][1],1)){
                re=1;
            }
            dp[i][iif]=max(dfs(mp[i][0],1),dfs(mp[i][1],1));
        }else{
            if()
        }
    }
    return dp[i][iif];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n!=0) {
        unordered_map<string,int> name;
        mp.resize(n+5);
        mp.clear();
        int cnt=1;
        string boss;
        cin>>boss;
        name[boss]=cnt++;
        for(int i=2;i<=n;i++){
            string t;
            cin>>t;
            name[t]=cnt++;
            string b;
            cin>>b;
            mp[name[b]].push_back(name[t]);
        }
        for(int i=1;i<=n;i++){
            cout<<i<<" : ";
            for(int j:mp[i])cout<<j<<" ";
            cout<<endl;
        }


        
        cin>>n;
    }
    return 0;
}