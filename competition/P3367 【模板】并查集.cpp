#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

vector<int> gnum;


int find(int x) {
    return gnum[x] == x ? x : (gnum[x] = find(gnum[x]));
}


void solve() {


    int n,m;
    cin>>n>>m;
    vector<int> nums(n+1,0);
    for(int i=0; i<nums.size(); i++){
        nums[i]=i;
    }
    gnum=nums;
    while(m--){
        int o;
        cin>>o;
        if(o==1){
            int x,y;
            cin>>x>>y;
            gnum[find(x)]=find(y);

        }else{
            int x,y;
            cin>>x>>y;
            if(find(x)==find(y)){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }


        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dashabi;
    
        solve();
    
    return 0;
}