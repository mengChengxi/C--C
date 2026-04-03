#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    
    int n, m ,k;
    cin >> n >> m >> k;
    int pos=0;
    vector<int> robots(n);
    vector<int> spikes(m);
    for(int i=0; i<n; i++){
        int r;
        cin >> r;
        robots[i]=r;
    }
    for(int i=0; i<m; i++){
        int r;
        cin >> r;
        spikes[i]=r;
    }
    sort(spikes.begin(),spikes.end());
    vector<pair<int,int>> interval(n);

    for(int i=0; i<n; i++){
        int l=INF;
        int u=-INF;
        auto lower = lower_bound(spikes.begin(), spikes.end(), robots[i]);//first element >= i
        auto upper = upper_bound
        (spikes.begin(), spikes.end(), robots[i]);//first element > i
        if(lower!=spikes.end()){
            l=*lower;
        }
        if(upper!=spikes.end() && (distance(spikes.begin(),upper)-1)>=0){
            u=spikes[distance(spikes.begin(),upper)-1];
        } else if( (distance(spikes.begin(),upper)-1)>=0&&spikes[distance(spikes.begin(),upper)-1]<robots[i]){
            u=spikes[distance(spikes.begin(),upper)-1];
        }
        interval[i]=mkp(robots[i]-u,l-robots[i]);
    }
    vector<pair<int,int>> linterval=interval;
    sort(linterval.begin(),linterval.end());
    std::sort(interval.begin(), interval.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second; // 升序排列
    });

    int out=n;

    
    string s;
    cin >> s;
    int rightmax=0;
    int leftmax=0;
    int right=0;
    int left=0;
    for(int i=0;i<k; i++){
        if(s[i]=='R'){
            pos++;
        }else{
            pos--;
        }
        rightmax=max(pos,rightmax);
        leftmax=-min(pos,-leftmax);
        while(right<n){
            if(interval[right].second<=rightmax){
                if(interval[right].first>leftmax){
                    out--;
                }
                right++;
            }else{
                break;
            }
        }
        
        while(left<n){
            if(linterval[left].first<=leftmax){
                if(linterval[left].second>rightmax){
                    out--;
                }
                left++;
            }else{
                break;
            }
        }
        
        cout<<out<<" ";
    }
    cout<<"\n";
    
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