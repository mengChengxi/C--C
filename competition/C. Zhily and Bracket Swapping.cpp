#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int safe1=0;
    int safe2=0;
    for(int i=0; i<n; i++){
        if(s1[i]=='('){
            safe1++;
        }else{
            safe1--;
        }
        if(s2[i]=='('){
            safe2++;
        }else{
            safe2--;
        }

        if(safe1<0){
            if(safe2<2){
                cout<<"NO"<<endl;
                return;
            }else{
                safe1+=2;
                safe2-=2;
            }
            
        }
        if(safe2<0){
            if(safe1<2){
                cout<<"NO"<<endl;
                return;
            }else{
                safe2+=2;
                safe1-=2;
            }
            
        }
    }
    if(safe2==0&&safe1==0){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
    
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