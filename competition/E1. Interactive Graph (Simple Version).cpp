#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

int isover(vector<int>& a){
    for(int i=1; i<a.size(); i++ ){
        if(a[i]==0){
            return 1;
        }
    }
    return 0;
}

void solve() {
    int n;
    cin>>n;
    
    vector<vector<int>> g(n+1);
    vector<int> over(n+1,0);
    vector<int> count(n+1,0);
    int k=1;
    cout<<"? "<<k<<endl;
    vector<int> last;
    int l;
    cin>>l;
    for(int i=0; i<l; i++){
        int tt;
        cin>>tt;
        last.push_back(tt);
    }
    count[last[0]]++;
    g[last[0]].push_back(last[1]);
    k++;

    while(isover(over)!=0){
        cout<<"? "<<k<<endl;
        vector<int> current;
        int l;
        cin>>l;
        if(l==0){
            break;
        }
        for(int i=0; i<l; i++){
            int tt;
            cin>>tt;
            current.push_back(tt);
        }
        for(int i=0; i<current.size()-1; i++){
            if(over[current[i]]==0){
                count[current[i]]++;
            }
            
        }
        if(current.size()>last.size()){
            if(over[current[current.size()-1]]==1){
                k+=count[current[current.size()-1]];
            }
            g[last[last.size()-1]].push_back(current[current.size()-1]);
            k++;
        }else{
            if(current[0]!=last[0]){
                if(over[current[0]]==1){
                    k--;//to avoid add more later.
                }
            }
            for(int i=0; i<current.size(); i++ ){
                if(current[i]!=last[i]){
                    for(int j=i; j<last.size(); j++){
                        over[last[j]]=1;
                    }
                    int first=0;
                    if(i==0){i=1; first=1;}
                    if(over[current[i-1]]==0){
                        g[current[i-1]].push_back(current[i]);
                    }
                    
                    if(over[current[i]]==1&&first==0){
                        k+=count[current[i]];
                    }else if(first==1&&over[current[i-1]]==1){
                        k+=count[current[i-1]];
                    }
                    break;
                }
            }
            k++;

        }

        last=current;

        int test=0;
        

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