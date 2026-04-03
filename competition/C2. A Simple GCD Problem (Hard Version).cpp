
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    int nums[n+2];
    nums[0]=1;
    nums[n+1]=1;
    int limit[n+2];
    limit[0]=1;
    limit[n+1]=1;
    for(int i=1; i<n+1; i++){
        int t;
        cin>>t;
        nums[i]=t;
    }
    for(int i=1; i<n+1; i++){
        int t;
        cin>>t;
        limit[i]=t;

    }
    int count=0;
    for(int i=1; i<n+1; i++)
    {
        int r=std::lcm(gcd(nums[i],nums[i-1]),gcd(nums[i],nums[i+1]));
        if((limit[i]>r&&(r!=nums[i]))){
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