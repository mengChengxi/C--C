#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int no=0;
    int n,m;
    cin>>n>>m;
    int prev=-1;
    int cont=1;
    for(int i=0; i<n; i++){
        int a;

        cin>>a;
        if(a==prev){
            cont++;
        }else{
            cont=1;
        }
        prev=a;
        if(cont==m){
            cout<<"NO"<<endl;
            no=1;
        }


    }
    if(no==0){
        cout<<"YES"<<endl;
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