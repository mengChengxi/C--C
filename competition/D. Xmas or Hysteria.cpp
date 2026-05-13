#include <bits/stdc++.h>
#include <future>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n,m;
    cin>>n>>m;
    
    vector<int> people(n);
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        people[i]=t;
    }
    if(m>n/2){
        cout<<-1<<endl;
        return;
    }
    //let the dead gay attack

    if(m==0){
        vector<pair<int, int>> remaining(n);
        for(int i=0; i<n; i++){
            remaining[i]={people[i],i};
        }
        sort(remaining.begin(),remaining.end());
        int boss=remaining[n-1].first;
        int start=-1;
        vector<int> out1;
        vector<int> out2;
        for(int i=0; i<n-1; i++){
            if(boss-remaining[i].first>0){
                boss-=remaining[i].first;
                
                out1.push_back(remaining[i].second+1);//dead
                out2.push_back(remaining[n-1].second+1);
            }else{
                start=i;
                break;
            }
        }

        if(start==-1){
            cout<<-1<<endl;
            return;
        }
        for(int i=start; i<n-1; i++){
            
            out1.push_back(remaining[i].second+1);
            out2.push_back(remaining[i+1].second+1);
        }
        cout<<out1.size()<<endl;
        for(int i=0; i<out1.size(); i++){
            cout<<out1[i]<<" "<<out2[i]<<endl;
        }
        
        



        return;
    }

    //m=10   9  1

    cout<<(m-1)+(n-2*(m-1))-1<<endl;

    for(int i=1; i<=m-1; i++){
        if(people[2*i-2]<people[2*i-1]){
            cout<<2*i<<" "<<2*i-1<<endl;
        }else{
            cout<<2*i-1<<" "<<2*i<<endl;
        }
        
    }



    vector<pair<int, int>> remaining(n-2*(m-1));
    for(int i=2*(m-1); i<n; i++){
        remaining[i-2*(m-1)]={people[i],i};
    }
    sort(remaining.begin(),remaining.end());


   
    for(int i=0; i<remaining.size()-1; i++){
        cout<<remaining[i+1].second+1<<" "<<remaining[i].second+1<<endl;
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