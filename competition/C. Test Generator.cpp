#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    long long s,m;
    cin>>s>>m;
    if(s%(m&(-m))!=0){
        cout<<-1<<endl;
        return;
    }


    
    // long long require=s/(m&(-m));
    // vector<long long> ava;
    
    // while((m&(-m))!=0){
    //     if(ava.size()>=1){
    //         ava.push_back(ava[ava.size()-1]+(m&(-m)));
    //     }else{
    //         ava.push_back(m&(-m));
    //     }
        
    //     m-=m&(-m);
    // }

    // long long maxn=0;
    // for(int i=ava.size()-1; i>=0; i--){
    //     if(s==0){
    //         break;
    //     }
    //     maxn=maxn+(s/ava[i]);
    //     s=s%ava[i];
    // }
    // cout<<maxn<<endl;
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