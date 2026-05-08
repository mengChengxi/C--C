#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    vector<long long > nums(n);
    for(int i=0; i<n; i++){
        int tt;
        cin>>tt;
        nums[i]=tt;
    }

    for(int i=nums.size()-2; i>=0; i--){
        if(nums[i+1]>=0){
            nums[i]+=nums[i+1];
        }
    }
    int count=0;
    for(int i=0; i<n; i++){
        if(nums[i]>0){
            count++;
        }
    }
    cout<<count<<endl;
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