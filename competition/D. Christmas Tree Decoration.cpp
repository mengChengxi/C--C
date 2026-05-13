#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=0; i<n+1; i++){
        int tt;
        cin>>tt;
        nums[i]=tt;
    }
    int sum=0;
    for(int i=0; i<n+1; i++){
        
        sum+=nums[i];
    }

    int more=sum%n;
    int turn=sum/n;
    int less=n-more;
    int mustmore=0;
    for(int i=1; i<n+1; i++){
        
        if(nums[i]==turn+1){
            mustmore++;
        }else if(nums[i]>turn+1){
            cout<<0<<endl;
            return;
        }
    }
    if(mustmore>more){
        cout<<0<<endl;
        return;
    }

    long long result=1;
    long long mod=998244353;
    // if(more==0){
    //     more=less;
    //     less=0;
    // }
    for(int i=more; i>=1; i--){
        result=(result*i)%mod;
    }
    for(int i=n-mustmore; i>=n-mustmore-less+1; i--){
        result=(result*i)%mod;
    }

    cout<<result<<endl;
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