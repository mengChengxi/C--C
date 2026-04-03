#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<long long, int, custom_hash> safe_map;
void solve() {
    safe_map.clear();
     // 预分配空间防止多次 rehash

    // mp[key] = val;      // 插入或修改
    // mp.count(key);      // 检查是否存在 (1 or 0)
    // mp.erase(key);      // 删除
    // for (auto const& [k, v] : mp) {  }

    int n,k;
    cin>>n;
    cin>>k;
    safe_map.reserve(k);
    vector<int> nums(n);
    vector<int> model(n);
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        nums[i]=t;

    }
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        model[i]=t;

    }

    for(int i=n-k; i<k; i++){
        safe_map[nums[i]]=1;

    }
//    1234567
//    1-4-3--



    for(int i=0; i<n; i++){
        if(model[i]==-1){
            continue;
        }
        if(n-k<=i&&i<k&&model[i]!=-1){
            if(safe_map.count(model[i])!=1||safe_map[model[i]]==2){
                cout<<"NO"<<endl;                
                return;
            }else{
                safe_map[model[i]]=2;
            }
        }
        else{
            if(model[i]!=nums[i]){
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