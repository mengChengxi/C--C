#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair
int n,m;
vector<string> g;

int ifin(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m){
        return 1;
    }
    return 0;
}

int judge(int i,int j,int direction){
    if(direction==1){
        //  .
        if(ifin(i-1,j)&&g[i-1][j]!='.'){
                return 0;
        }
        if(ifin(i-1,j+1)&&g[i-1][j+1]!='.'){
                return 0;
        }
        if(ifin(i-1,j+2)&&g[i-1][j+2]!='.'){
                return 0;
        }
        if(ifin(i,j-1)&&g[i][j-1]!='.'){
                return 0;
        }
        if(ifin(i,j)&&g[i][j]!='.'){
                return 0;
        }
        if(ifin(i,j+2)&&g[i][j+2]!='.'){
                return 0;
        }
        if(ifin(i+1,j-1)&&g[i+1][j-1]!='.'){
                return 0;
        }
        if(ifin(i+1,j+2)&&g[i+1][j+2]!='.'){
                return 0;
        }
        if(ifin(i+1,j-1)&&g[i+1][j-1]!='.'){
                return 0;
        }
        if(ifin(i+2,j-1)&&g[i+2][j-1]!='.'){
                return 0;
        }
        if(ifin(i+2,j)&&g[i+2][j]!='.'){
                return 0;
        }
        if(ifin(i+2,j+1)&&g[i+2][j+1]!='.'){
                return 0;
        }
        if(ifin(i+2,j+2)&&g[i+2][j+2]!='.'){
                return 0;
        }
        return 1;

    }
    if(direction==2){
        //  .
        if(ifin(i-1,j)&&g[i-1][j]!='.'){
                return 0;
        }
        if(ifin(i-1,j+1)&&g[i-1][j+1]!='.'){
                return 0;
        }
        if(ifin(i,j+1)&&g[i][j+1]!='.'){
                return 0;
        }
        if(ifin(i,j-1)&&g[i][j-1]!='.'){
                return 0;
        }
        if(ifin(i-1,j-1)&&g[i-1][j-1]!='.'){
                return 0;
        }
        if(ifin(i,j+2)&&g[i][j+2]!='.'){
                return 0;
        }
        if(ifin(i+1,j-1)&&g[i+1][j-1]!='.'){
                return 0;
        }
        if(ifin(i+1,j+2)&&g[i+1][j+2]!='.'){
                return 0;
        }
        if(ifin(i+1,j-1)&&g[i+1][j-1]!='.'){
                return 0;
        }
        if(ifin(i+2,j-1)&&g[i+2][j-1]!='.'){
                return 0;
        }
        if(ifin(i+2,j)&&g[i+2][j]!='.'){
                return 0;
        }
        if(ifin(i+2,j+1)&&g[i+2][j+1]!='.'){
                return 0;
        }
        if(ifin(i+2,j+2)&&g[i+2][j+2]!='.'){
                return 0;
        }
        return 1;

    }
    if(direction==3){
        //  .
        if(ifin(i-1,j)&&g[i-1][j]!='.'){
                return 0;
        }
        if(ifin(i-1,j+1)&&g[i-1][j+1]!='.'){
                return 0;
        }
        if(ifin(i-1,j+2)&&g[i-1][j+2]!='.'){
                return 0;
        }
        if(ifin(i,j-1)&&g[i][j-1]!='.'){
                return 0;
        }
        if(ifin(i-1,j-1)&&g[i-1][j-1]!='.'){
                return 0;
        }
        if(ifin(i,j+2)&&g[i][j+2]!='.'){
                return 0;
        }
        if(ifin(i+1,j-1)&&g[i+1][j-1]!='.'){
                return 0;
        }
        if(ifin(i+1,j+2)&&g[i+1][j+2]!='.'){
                return 0;
        }
        if(ifin(i+1,j-1)&&g[i+1][j-1]!='.'){
                return 0;
        }
        if(ifin(i+1,j)&&g[i+1][j]!='.'){
                return 0;
        }
        if(ifin(i+2,j)&&g[i+2][j]!='.'){
                return 0;
        }
        if(ifin(i+2,j+1)&&g[i+2][j+1]!='.'){
                return 0;
        }
        if(ifin(i+2,j+2)&&g[i+2][j+2]!='.'){
                return 0;
        }
        return 1;

    }
    if(direction==4){
        //  .
        if(ifin(i-1,j)&&g[i-1][j]!='.'){
                return 0;

        }
        if(ifin(i-1,j+1)&&g[i-1][j+1]!='.'){
                return 0;
        }
        if(ifin(i-1,j+2)&&g[i-1][j+2]!='.'){
                return 0;
        }
        if(ifin(i,j-1)&&g[i][j-1]!='.'){
                return 0;
        }
        if(ifin(i-1,j-1)&&g[i-1][j-1]!='.'){
                return 0;
        }
        if(ifin(i,j+2)&&g[i][j+2]!='.'){
                return 0;
        }
        if(ifin(i+1,j-1)&&g[i+1][j-1]!='.'){
                return 0;
        }
        if(ifin(i+1,j+2)&&g[i+1][j+2]!='.'){
                return 0;
        }
        if(ifin(i+1,j-1)&&g[i+1][j-1]!='.'){
                return 0;
        }
        if(ifin(i+2,j-1)&&g[i+2][j-1]!='.'){
                return 0;
        }
        if(ifin(i+2,j)&&g[i+2][j]!='.'){
                return 0;
        }
        if(ifin(i+2,j+1)&&g[i+2][j+1]!='.'){
                return 0;
        }
        if(ifin(i+1,j+1)&&g[i+1][j+1]!='.'){
                return 0;
        }
        return 1;

    }
    
}
    

void solve() {
    

    cin>>n>>m;

    vector<string> rg(n);
    
    for(int i=0; i<n ; i++){
        string tt;
        cin>>tt;
        rg[i]=tt;
    }
    g=rg;


    for(int i=0; i<n ; i++){
        char last=g[i][0];
        for(int j=1; j<m; j++){
            if(last=='*' && g[i][j]=='*'){
                // [i-1][j-1] [i-1][j] 
                g[i][j-1]='.';   g[i][j]='.';
                // [i+1][j-1] [i+1][j]

                if(ifin(i-1,j-1)&&g[i-1][j-1]=='*'){
                    if(judge( i-1,  j-1,2)){
                        g[i-1][j-1]='.';
                        continue;
                    }else{
                        cout<<"NO"<<endl;
                        return;
                    }
                    
                }   
                if(ifin(i-1,j)&&g[i-1][j]=='*'){
                    if(judge( i-1,  j-1,1)){
                        g[i-1][j]='.';
                        continue;
                    }else{
                        cout<<"NO"<<endl;
                        return;
                    }
                }
                if(ifin(i+1,j-1)&&g[i+1][j-1]=='*'){
                    if(judge( i,  j-1,4)){
                        g[i+1][j-1]='.';
                        continue;
                    }else{
                        cout<<"NO"<<endl;
                        return;
                    }
                }
                if(ifin(i+1,j)&&g[i+1][j]=='*'){
                    if(judge( i,  j-1,3)){
                        g[i+1][j]='.';
                        continue;
                    }else{
                        cout<<"NO"<<endl;
                        return;
                    }
                }
                cout<<"NO"<<endl;
                return;
               


            }
            last=g[i][j];


        }

        
    }

    for(int 
        i=0; i<n; i++)
    {
        for (int j=0; j<m; j++) {
            if(g[i][j]=='*'){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;

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