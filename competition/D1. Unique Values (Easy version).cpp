#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair
int result[3];
int ask(int point){
    int count=0;
    for(int i=0; i<3; i++){
        if(result[i]!=-1){
            count++;
        }
    }
    cout<<"? "<<point+count<<" ";
    for(int i=0; i<3; i++){
        if(result[i]!=-1){
            cout<<result[i]<<" ";
        }
    }

    for(int i=1; i<=point; i++){
        cout<<i<<" ";
    }
    cout<<endl;
    int result;
    cin>>result;
    if((result-point-count)%2!=0){
        return 3;
    }
    return 0;

}

void solve() {
    
    int n;
    cin>>n;
    int point=n;

    result[0]=-1;
    result[1]=-1;
    result[2]=-1;
    //inclusive
    int start=1;
    int end=2*n+1;
    for(int i=0; i<3; i++){
        
        while(start<end){
            point=(start+end)/2;//point included
           
            if(ask(point)==0){
                start=point+1;
            }else{
                end=point;
            }
        }
        result[i]=start;
        end=start-1;
        start=1;
    }
    cout<<"! "<<result[0]<<" "<<result[1]<<" "<<result[2]<<endl;
   

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