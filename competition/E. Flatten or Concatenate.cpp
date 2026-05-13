#include <bits/stdc++.h>
#include <ios>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

int findmid(int right, int left, long long targetsum){
    int oleft=left;
    while(right>left){
        int mid=(left+right)/2;
        cout<<"? "<<oleft<<" "<<mid<<endl;
        fflush(stdout);
        long long sum;
        cin>>sum;
        if(sum==targetsum){
            return mid;
        }else if(sum<targetsum){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return right;
    
}

void solve() {
    int l;
    cin>>l;
    cout<<"? 1 "<<l<<endl;
    long long currentsum;
    cin>>currentsum;
    long long targetsum=currentsum/2;

    int right=l;
    int left=1;

    if(l==1){
        cout<<"! "<<currentsum<<endl;
        return;
    }

    while(right>left){

        int mid=findmid(right,left,targetsum);
        if(mid-left>right-(mid+1)){
            left=mid+1;
        }else{
            right=mid;
        }
        if(targetsum>=2){
            targetsum/=2;
        }else{
            cout<<"! "<<1<<endl;
            return;
        }
        
    
    }
    cout<<"! "<<targetsum*2<<endl;

    



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