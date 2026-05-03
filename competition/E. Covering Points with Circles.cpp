
#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair
bool ccc(const std::pair<int, int>& a, const std::pair<int, int>& b) {
return a.first < b.first; // 基础的升序排列
}
bool has_data_in_dual_range(const std::vector<std::pair<int, int>>& vec, 
                            int x_min, int x_max, 
                             int y_min, int y_max) {
    
    // 1. 先根据第一个维度 (first) 进行二分查找，定位到第一个可能满足条件的位置
    // 注意：默认 pair 的排序是先比 first，再比 second
    auto it = std::lower_bound(vec.begin(), vec.end(), std::make_pair(x_min, (int)-2147483648)); // 最小可能的 int

    // 2. 从该位置开始向后遍历
    while (it != vec.end() && it->first <= x_max) {
        // 3. 检查第二个维度 (second) 是否也符合要求
        if (it->second >= y_min && it->second <= y_max) {
            return true; // 找到了！
        }
        ++it;
    }

    return false;
}
void solve() {
    int n,r;
    cin>>n>>r;

    vector<pair<int,int>> coordinates(n);
    
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x;
        cin>>y;
        coordinates[i].first=x;
        coordinates[i].second=y;
        
    }
    int top=coordinates[0].second;
    int bottom=coordinates[0].second;
    int right=coordinates[0].first;
    int left=coordinates[0].first;

    for(int i=0 ; i<n; i++){
        top=max( coordinates[i].second,top);
        bottom=min( coordinates[i].second,bottom);
        right=max(coordinates[i].first,right);
        left=min(coordinates[i].first,left);
    }
    vector<pair<int , int>> circles;
    sort(coordinates.begin(),coordinates.end(),ccc);
    int indention=0;
    int h=(int)(sqrt(3.0)*r)+1;
    for(int i=top; i>bottom-r; i-=h ){
        for (int j=left+indention;j<right+r ; j+=2*r ) {
            if(has_data_in_dual_range(coordinates,j-r,j+r,i-r,i+r  )){
                circles.push_back({j,i});
            }
            
        }
        indention=r-indention;
    }
    cout<<circles.size()<<endl;
    for(int i=0 ;i<circles.size(); i++){
        cout<<circles[i].first<<" "<<circles[i].second<<endl;
    }

    
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dashabi;
    
        solve();
    
    return 0;
}