#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int t;
    cin>>t;
    string s;

    cin>>s;
    char c=s[0];
    int block =1;
    int have=0;
    for(int i=1; i<s.size(); i++){
        if(s[i]!=c){
            block++;
        }else{
            have=1;
        }
        c=s[i];
    }
    if(block!=1&&s[0]==s[s.size()-1]){
        block--;
        have=1;
    }
    if(block==1){
        cout<<1<<endl;
    }else if(have==1){
        cout<<block+1<<endl;
    }else{
        cout<<s.size()<<endl;
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