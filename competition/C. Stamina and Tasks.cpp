#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    int c[n];
    int p[n];
    for(int i=0; i<n; i++){
        int cc, pp;
        cin>>cc>>pp;
        c[i]=cc;
        p[i]=pp;

    }
    double current=0.0;
    for(int i=n-1; i>=0; i--){
        current=max(current*(100.0-p[i])/100.0+c[i],current);
  
    }
    std::cout << std::setprecision(std::numeric_limits<double>::max_digits10) << current<<endl;


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