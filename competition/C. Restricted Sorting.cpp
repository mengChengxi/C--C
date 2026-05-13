#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        int tt;
        cin>>tt;
        nums[i]=tt;
    }
    vector<int> snums=nums;
    sort(snums.begin(),snums.end());
    int maxn=snums[n-1];
    int minn=snums[0];
    int k=INF;
    for(int i=0; i<n; i++){
        if(snums[i]!=nums[i]){
            k=min(k,max(maxn-nums[i],nums[i]-minn));

        }
    }
    if(k==INF){
        cout<<-1<<endl;
    }else{
        cout<<k<<endl;
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