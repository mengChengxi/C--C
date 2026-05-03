#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    string s;
    cin>>s;
    int count=0;
    for(int i=0; i<s.length()-1; i++){
        if(s[i]==s[i+1]){
            count++;
        }
    }
    if(count>2){
        cout<<"NO"<<endl;

    }else{
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