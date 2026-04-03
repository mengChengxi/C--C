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
unordered_map<long long, int, custom_hash> upper;
unordered_map<long long, int, custom_hash> lower;

void solve() {
    unordered_map<long long, int, custom_hash> upper;
    unordered_map<long long, int, custom_hash> lower;
    
     // 预分配空间防止多次 rehash

    // mp[key] = val;      // 插入或修改
    // mp.count(key);      // 检查是否存在 (1 or 0)
    // mp.erase(key);      // 删除
    // for (auto const& [k, v] : mp) {  }

    int n,k;
    cin>>n;
    cin>>k;
    upper.reserve(2*k);
    lower.reserve(2*k);
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
    for(int i=0; i<k; i++){
        if(upper.count(nums[i])==1){
            upper[nums[i]]+=1;
        }else{
            upper[nums[i]]=1;
        }
        if(model[i]!=-1 ){
            if(lower.count(model[i])==1){
                lower[model[i]]+=1;
            }else{
                lower[model[i]]=1;
            }
        }

    }
    for(int i=0; i<k; i++){
        if(model[i]!=-1){
            if(upper.count(model[i])!=1||upper[model[i]]<lower[model[i]]){
                cout<<"NO"<<endl;
                return;
            } 
        }
    }

    for(int i=0; i<n-k; i++){
        
        int upperremoved=nums[i];
        
        int loweradded=model[i+k];
        if(upperremoved==nums[i+k]){
            if(loweradded!=-1&&model[i]!=-1&&loweradded!=model[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
        upper[nums[i]]-=1;
        if(upper.count(nums[i+k])==1){
            upper[nums[i+k]]+=1;
        }else{
            upper[nums[i+k]]=1;
        }

        if(model[i]!=-1){
            lower[model[i]]-=1;
        }
        if(model[i+k]!=-1){
            if(lower.count(model[i+k])==1){
                lower[model[i+k]]+=1;
            }else{
                lower[model[i+k]]=1;
            }
        }
        if(lower.count(upperremoved)==1&&upper[upperremoved]<lower[upperremoved]){
            cout<<"NO"<<endl;
            return;
        }
        if(loweradded!=-1){
            if(upper.count(loweradded)!=1){
                
                cout<<"NO"<<endl;
                return;
            }
            if(upper[loweradded]<lower[loweradded]){
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