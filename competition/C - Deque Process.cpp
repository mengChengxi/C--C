#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    int right=n-1;
    
    int left=1;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        nums[i]=t;
    }
    int l=0;
    int current=nums[0];
    cout<<"L";
    for(int i=0; i<n-1; i++){
        if(current<nums[left]&&current<nums[right]){
            if(nums[left]>nums[right]){
                current=nums[left];
                left++;
                cout<<"L";
                
            }else{
                current=nums[right];
                right--;
                cout<<"R";
            }
        }else if(current>nums[left]&&current>nums[right]){
            if(nums[left]<nums[right]){
                current=nums[left];
                left++;
                cout<<"L";
                
            }else{
                current=nums[right];
                right--;
                cout<<"R";
            }
        }else{
            if(l==1){
                current=nums[left];
                left++;
                cout<<"L";
                l=0;
            }else{
                current=nums[right];
                right--;
                cout<<"R";
                l=1;
            }
            
        }
        // 3 4 5 8 5 7 1

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