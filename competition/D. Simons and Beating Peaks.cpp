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
    for(int i=0; i<n; i++){
        int tt;
        cin>>tt;
        nums[i]=tt;
    }

    // index of max num in the left

    vector<int> leftmax(n);
    vector<int> stack;

    for(int i=0; i< n;i++){
        for(int j=stack.size()-1; j>=0; j--){
            if(nums[stack[j]]<=nums[i]){
                stack.pop_back();
            }else{
                break;
            }
        }
        if(stack.size()>=1){
            leftmax[i]=stack[stack.size()-1];
        }else{
            leftmax[i]=-1;
        }
        stack.push_back(i);
    }
    stack.clear();
    vector<int> rightmax(n);
    for(int i=n-1; i>=0;i--){
        for(int j=stack.size()-1; j>=0; j--){
            if(nums[stack[j]]<=nums[i]){
                stack.pop_back();
            }else{
                break;
            }
        }
        if(stack.size()>=1){
            rightmax[i]=stack[stack.size()-1];
        }else{
            rightmax[i]=-1;
        }
        stack.push_back(i);
    }


    

    vector<int> leftdp(n);
    for(int i=0; i<n; i++){
        if(leftmax[i]==-1){
            leftdp[i]=1;
        }else{
            leftdp[i]=leftdp[leftmax[i]]+1;
        }
    }

    vector<int> rightdp(n);
    for(int i=n-1; i>=0; i--){
        if(rightmax[i]==-1){
            rightdp[i]=1;
        }else{
            rightdp[i]=rightdp[rightmax[i]]+1;
        }
    }

    // for(int i=0; i<n; i++){
    //     cout<<rightdp[i]<<" ";
    // }

    int maxn=-1;
    for(int i=0; i<n; i++){
        maxn=max(maxn, rightdp[i]+leftdp[i]-1);
    }

    cout<<n-maxn<<endl;
    
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