#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    
    int n;
    cin>>n;
    int num[n];
    for(int  i=0; i<n;i++){
        int t;
        cin>>t;
        num[i]=t;
    }
    for(int i=0; i<n;i++){
        int s=0;
        int l=0;
        for(int j=i; j<n ; j++){
            if(num[j]<num[i]){
                s++;
            }
            if(num[j]>num[i]){
                l++;
            }
            
        }
        cout<<max(l,s)<<" ";

    }
    cout<<endl;
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