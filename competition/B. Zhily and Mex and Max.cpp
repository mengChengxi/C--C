#include <algorithm>
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
    for(int i=0; i<n; i++)
    {
        int tt;
        cin>>tt;
        nums[i]=tt;
    }

    sort(nums.begin(), nums.end());
    int current=-1;
    
    for(int i=0; i<n; i++){
        if(nums[i]==current+1){
            current++;
        }else{
            break;
        }
        
    }
    current++;
    // 0,1,2,3,4,5,6,10,10
    // 1,2,3,4,5,6,c,c,c,c,c,max
    int maxx=0;
    for(int i=0; i<current; i++){
        maxx=max(maxx,i+(0+i)*(i)/2+(n-i)*nums[n-1]);
    }
    int sum=maxx+(current+1)*current/2+(n-current)*current;

    

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