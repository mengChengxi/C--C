#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n+1,0);
    for(int i=0; i<n-1 ; i++){
        int t;
        cin>>t;
        nums[t]=1;

    }
    for(int i=1;i<n+1;i++){
        if(nums[i]==0){
            cout<<i<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    solve();
    
    return 0;
}