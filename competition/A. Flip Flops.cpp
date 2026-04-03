#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    
    long long n,c,k;
    cin>>n>>c>>k;
    vector<int> monster(n);
    for(int i=0; i<n; i++){
        long long m;
        cin>>m;
        monster[i]=m;
    }
    sort(monster.begin(),monster.end());
    for(int i=0; i<n; i++){
        if(monster[i]>c){
            cout<<c<<endl;
            return;
        }else{
            if(k-(c-monster[i])>0){
                k=k-(c-monster[i]);
                c+=c;
            }else{
                c+=monster[i]+k;
                k=0;
            }
        }
    }
    cout<<c<<endl;
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