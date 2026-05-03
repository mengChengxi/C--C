#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <iterator>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        nums[i]=a;
    }
    sort(nums.begin(),nums.end(),greater<int>());
    for(int i=1; i<n; i++){
        if(nums[i-1]==nums[i]){
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
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