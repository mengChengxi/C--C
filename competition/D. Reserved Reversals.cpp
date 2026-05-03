#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin>>n;
    int nums[n];
    int maxt=-INF;
    int mint=INF;
    for(int i=0; i<n; i++){
        int tt;
        cin>>tt;
        maxt=max(maxt,tt);
        mint=min(mint,tt);

        nums[i]=tt;
    }
    int alleven=0;
    if(maxt%2==0){
        if(mint%2==0){
            alleven=1;
        }else{
            cout<<"YES"<<endl;
            return;
        }
    }else{
        if(mint%2==0){
            cout<<"YES"<<endl;
            return;
        }else{
            
        }

    }

    vector<int> odd;
    vector<int> even;
    for(int i=0; i<n; i++){
        if(nums[i]%2==0){
            even.push_back(nums[i]);
        }else{
            odd.push_back(nums[i]);
        }
    }


    if(alleven==1){
        int start=0;
        int oddmax=-INF;
        int oddmin=INF;
        for(int i=0; i<odd.size(); i++){
            oddmax=max(oddmax,odd[i]);
            oddmin=min(oddmin,odd[i]);
        }
        if(oddmax==-INF){
            for(int i=0; i<even.size()-1; i++){
                if(even[i]>even[i+1]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            cout<<"YES"<<endl;
            return;

        }
        for(int i=0; i<even.size(); i++){
            if(even[i]>oddmax){
                start=1;
            }
            if(start==1&&even[i]<oddmin){
                cout<<"NO"<<endl;
                return;
            }
        }
        
    }else{
        int start=0;
        int evenmax=-INF;
        int evenmin=INF;
        for(int i=0; i<even.size(); i++){
            evenmax=max(evenmax,even[i]);
            evenmin=min(evenmin,even[i]);
        }
        if(evenmax==-INF){
            for(int i=0; i<odd.size()-1; i++){
                if(odd[i]>odd[i+1]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
            cout<<"YES"<<endl;
            return;
        }
        for(int i=0; i<odd.size(); i++){
            if(odd[i]>evenmax){
                start=1;
            }
            if(start==1&&odd[i]<evenmin){
                cout<<"NO"<<endl;
                return;
            }
        }

    }
    cout<<"YES"<<endl;
    return;
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