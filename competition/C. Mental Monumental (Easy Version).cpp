#include <bits/stdc++.h>
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

    vector<int> rava(n);
    for(int i=0; i<n; i++){
        if(nums[i]<=n-1){
            rava[nums[i]]++;
        }
        
    }
    sort(nums.begin(),nums.end());
    int left=0;
    int right=n;
    int mid;
    while(right>left){
        mid=(right+left)/2;
        int finished=0;
        auto ava=rava;
        int p=nums.size()-1;
        for(int i=mid; i>=0; i--){
            if(ava[i]>0){
                ava[i]--;
            }else{
                //
                if(nums[p]<=n-1){
                    if(ava[nums[p]]>0){

                    }else{
                        p--;
                        i++;
                        continue;
                    }
                }
                if((nums[p]-1)/2>=i){
                    if(nums[p]<=n-1){
                        ava[nums[p]]--;
                    }
                    p--;
                }else{
                    right=mid;
                    finished=1;
                    break;
                }
            }
        }
        if(finished==0){
            left=mid+1;
        }
        
    }
    cout<<left<<endl;
    


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