#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;


const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n,k,p,q;
    cin>>n>>k>>p>>q;
    vector<int> nums(n);
    vector<int> minnums(n);
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        nums[i]=t;
    }
    for(int i=0; i<n; i++){
        minnums[i]=min(nums[i]%p%q,nums[i]%q%p);
    }
    
    
    long long currentlost=0;
    for(int i=0; i<k;i++){
        currentlost+=(nums[i]%p%q-minnums[i]);
    }
    long long minlost=currentlost;
    if(currentlost<minlost){
        minlost=currentlost;
   
    }
    for(int i=k; i<n; i++){
        //[n,n+k)
        currentlost+=(nums[i]%p%q-minnums[i]);
        currentlost-=(nums[i-k]%p%q-minnums[i-k]);
        if(currentlost<minlost){
            minlost=currentlost;
     
        }
    }
    currentlost=0;
    for(int i=0; i<k;i++){
        currentlost+=(nums[i]%q%p-minnums[i]);
    }
    if(currentlost<minlost){
        minlost=currentlost;
    }
    for(int i=k; i<n; i++){
        //[n,n+k)
        currentlost+=(nums[i]%q%p-minnums[i]);
        currentlost-=(nums[i-k]%q%p-minnums[i-k]);
        if(currentlost<minlost){
            minlost=currentlost;
  
        }
    }

    long long sum=0;
    for(int i=0; i<n; i++){
        // if(start<=i&&i<end){
        //     continue;
        // }
        sum+=minnums[i];
    }
    sum+=minlost;

    cout<<sum<<endl;


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