#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int x,y;
    cin>>x>>y;
    int ox=x;
    int fy=0;
    for(int i=0; i<31; i++){
        

        if(x%2==1&&y%2==1){
            fy=fy<<1;
        }else{
            fy+=(y%2)*(1<<3);
        }
        x=x>>1;
        y=y>>1;
    }

    cout<<ox<<" "<<fy<<endl;

   


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