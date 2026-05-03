#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n,l,r;
    cin>>n>>l>>r;
    int nums[n];
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        nums[i]=t;
    }
    int sum=0;
    int win=0;
    int start=0;
    int end=-1;
    while(1){
        if(sum>=l&&sum<=r){
            win++;
            start=end+1;
            sum=0;
        }
        if(sum>r){
            sum-=nums[start];
            start++;
            continue;
        }
        if(sum<l){
            
            end++;
            if(end>=n){
                break;
            }
            sum+=nums[end];
            continue;
        }
       
    }
    
    cout<<win<<endl;

    
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