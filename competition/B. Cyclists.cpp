#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    
    int n,k,p,m;
    cin>>n>>k>>p>>m;
    k--;
    int pp=0;
    vector<int> cards(n-1);
    for(int i=0; i<n; i++)
    {

        int t;
        cin>>t;
        if(i!=p-1){
            cards[i]=t;
        }else{
            pp=t;
            i--;
        }
        cards[i]=t;
        
    }
    vector<int> tc=cards;
    sort(tc.begin(),tc.end());
    int maxk[k-1];
    int minl=0;
    int j=0;
    for(int i=0; i<n-2; i++){
        minl+=tc[i];
     
    }
    if(p<=k){
        int sum=0;
        for(int i=0; i<n-2-k+1; i++){
            sum+=tc[i];
        }
        cout<<m/(sum+pp);
        return;
    }
    vector<int> pk(p-1);
    for(int i=0; i<p-1; i++){
        cards[i]=pk[i];
    }
    sort(pk.begin(),pk.end());
    int sum=0;
    for(int i=0; i<p-k;i++){
        sum+=pk[i];
    }
    if(m<sum){
        cout<<0;
        return;
    }
    cout<<(m-sum)/(minls);
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