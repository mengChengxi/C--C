#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    long long a,b,c,m;
    cin>>a>>b>>c>>m;
    long long ab=m/lcm(a,b);
    long long bc=m/lcm(c,b);
    long long ac=m/lcm(a,c);
    long long abc=m/lcm(lcm(a,b),c);

    cout<<(m/a-ab-ac+abc)*6+(ab+ac-2*abc)*3+abc*2<<" ";
    cout<<(m/b-ab-bc+abc)*6+(ab+bc-2*abc)*3+abc*2<<" ";
    cout<<(m/c-bc-ac+abc)*6+(bc+ac-2*abc)*3+abc*2<<endl;


    

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