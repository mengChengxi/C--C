#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> evena;
    vector<int> odda;
    int x[m];
    long long sum=0;
    for(int i=0; i<n; i++){
        int tt;
        cin>>tt;
        sum+=tt;
        if(i%2==0){
            odda.push_back(tt);
        }else{
            evena.push_back(tt);
        }
        
    }
    sort(odda.begin(),odda.end(),[](int a,int b){
        return a>b;
    });
    sort(evena.begin(),evena.end(), [](int a,int b){
        return a>b;
    });

    int even=0;
    int odd=0;
    for(int i=0; i<m; i++){
        int tt;
        cin>>tt;
        x[i]=tt;
        if(tt%2==0){
            even++;
        }else{
            odd++;
        }
    }
    long long ms=0;
    for(int i=0; i<evena.size(); i++){
        if(i<even && (evena[i]>0||i==0)){
            ms+=evena[i];
        }else{
            break;
        }
    }
    for(int i=0; i<odda.size(); i++){
        if(i<odd && (odda[i]>0||i==0)){
            ms+=odda[i];
        }else{
            break;
        }
    }

    cout<<sum-ms<<endl;


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