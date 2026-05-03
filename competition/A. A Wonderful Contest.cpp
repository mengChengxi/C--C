#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    int can =0;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        if(num==100){
            can =1;
        }
    }
    if(can==1){
        cout<<"Yes"<<"\n";
    }else{
         cout<<"No"<<"\n";
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