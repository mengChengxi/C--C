
#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> limit(k);
    vector<int> initial_course(n);
    vector<int> operation(0);
    for(int i=0; i<k; i++){
        int a;
        cin>>a;
        limit[i]=a;
    }
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        initial_course[i]=a;
    }

    for(int i=k; i>=1; i--){
        for(int j=0; j<n; j++){
            if(initial_course[j]==i){
                for(int l=i; l<k+1; l++){
                    if(operation.size()<=1000){
                        operation.push_back(j+1);
                    }else{
                        cout<<-1<<endl;
                        return;
                    }
                    
                }
            }
        }
    }
    cout<<operation.size()<<endl;
    for(int i=0; i<operation.size(); i++){
        cout<<operation[i]<<" ";
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