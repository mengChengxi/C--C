#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n,m;    
    cin>>n>>m;
    int table[n][m];

    int ones=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tt;
            cin>>tt;
            if(tt==1){
                ones++;
                table[i][j]=1;
            }else{
                table[i][j]=0;
            }
            
        }
    }
    long long target;
    if(ones%2==0){
        target=ones/2;
    }else{
        target=ones/2+1;
    }
   
    cout<<target*(ones-target)<<endl;
    for(int i=0; i<n; i++){
        for(int j=m-1; j>=0; j--){
            target-=table[i][j];
            
            if(target==0){

                
                for(int ii=0; ii<i; ii++){
                    cout<<"D";
                }
                for(int jj=0;jj<j; jj++){
                    cout<<"R";
                }
                cout<<"D";
                for(int jj=0;jj<m-j; jj++){
                    cout<<"R";
                }
                for(int jj=0;jj<n-i-1; jj++){
                    cout<<"D";
                }
                cout<<endl;
                return;

            }
            

            
        }
    }


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