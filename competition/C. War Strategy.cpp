#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    int left=k-1;
    int right=n-k;
    if(left>right){
        int temp=right;
        right=left;
        left=temp;
    }
   // right>left
    int rc=0;
    int lc=0;

    while (rc<right) {
        rc+=1;
        m-=rc;

        if(m<0){
            rc--;
            break;
        }

        if(lc<left){
            lc+=1;
            m-=lc;
        }
        if(m<0){
            lc--;
            break;
        }
    }
    cout<<lc+rc+1<<endl;
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