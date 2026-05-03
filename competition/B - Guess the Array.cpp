#include <bits/stdc++.h>
#include <math.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int l;
    cin>>l;
    int result[l];
    //a+b=x
    //a+c=y
    //b+c=z

    //b-c=x-y
    //b=z+x-y/2
    int x, y,z;
    cout<<"? 1 2"<<endl;
    fflush(stdout);
    cin>>x;

    cout<<"? 1 3"<<endl;
    fflush(stdout);
    cin>>y;
    cout<<"? 2 3"<<endl;
    fflush(stdout);
    cin>>z;

    result[1]=(z+x-y)/2;
    result[2]=z-result[1];
    result[0]=y-result[2];
    for(int i=4; i<=l; i++){
        cout<<"? 1 "<<i<<endl;
        fflush(stdout);
        int r;
        cin>>r;
        result[i-1]=r- result[0];
    }   
    cout<<"!";

    for(int i=0; i<l; i++){
        cout<<" "<<result[i];
    }
    cout<<endl;
    fflush(stdout);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    solve();
    
    return 0;
}