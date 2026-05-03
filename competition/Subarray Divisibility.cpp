#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int t;
    cin>>t;
    long long psum[t+1];
    long long sum=0;
    for(int i=0; i<t ;i++){
        int n;
        cin>>n;

        psum[i]=sum;
        sum=((sum+n)%t+t)%t;
    }
    psum[t]=sum;
    //n:  n+1  -  n
    //[a,b); b-a

    vector<int> re(t,0);
    long long count=0;
    for(int i=0; i<t+1; i++){
        count+=re[((psum[i]%t)+t)%t];
        re[((psum[i]%t)+t)%t]++;
    }
    cout<<count<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}