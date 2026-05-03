#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int only;
    int num=0;
    for(int i=0; i<15; i++ ){
        cout<<p[i]<<endl;
        fflush(stdout);
        string r;
        cin>>r;
        
        if(r=="yes"){
            only=p[i];
            num++;
        }

    }
        if(num==0){
            cout<<"prime"<<endl;
            fflush(stdout);
            return;
        }
        if(num>=2){
            cout<<"composite"<<endl;
            fflush(stdout);
            return;
        }
        if(num==1){
            if(only*only>100){
                cout<<"prime"<<endl;
                fflush(stdout);
                return;
            }
            cout<<only*only<<endl;
            fflush(stdout);
            string r;
            cin>>r;
            
            if(r=="yes"){
                cout<<"composite"<<endl;
                fflush(stdout);
            }else{
                cout<<"prime"<<endl;
                fflush(stdout);
            }
        }

    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}