#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    long long n, x;
    int m=998244353;
    cin>>n>>x;
    long long before=x/4+1;
    long long after=(n+1)/4+1-before;
    long long result=((before%m)*(after%m))%m;
    before = (x+2)/4;
    after = (n+3)/4-before;
    result+=((before%m)*(after%m))%m;
    cout<<result%m<<endl;


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