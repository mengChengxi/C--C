#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    //  (()) ()()()
    //   ((()))
     

    for(int i=1; i<n-2; i++){
        if(s[i]==')'&&s[i-1]=='('){
            if(s[i+1]=='('&&s[i+2]=='('){
                cout<<n-2<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;

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