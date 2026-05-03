#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    unordered_map<int, vector<pair<int,int>>> mp;
    mp.reserve(100005); // 预分配空间防止多次 rehash
    // mp[key] = val;      // 插入或修改
    // mp.count(key);      // 检查是否存在 (1 or 0)
    // mp.erase(key);      // 删除
    // for (auto const& [k, v] : mp) {  }

    int n;
    cin>>n;
    vector<int>nums(n);
    int result[n];
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        nums[i]=t;
    }
    for(int i=0; i<n; i++){
        
        mp[nums[i]/4].push_back({i,nums[i]});
        
    }
    for (auto& [k, v] : mp) {  

        vector<pair<int, int>> v1=v;
        sort(v.begin(), v.end(), []( auto& a,  auto& b) {
        return a.second < b.second; // 升序
        });
        sort(v1.begin(), v1.end(), []( auto& a,  auto& b) {
        return a.first < b.first; // 升序
        });
        for(int i=0; i<v.size(); i++){
            result[v1[i].first]=v[i].second;
        }
    }
    for(int i=0 ; i<n; i++){
        cout<<result[i]<<" ";
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

