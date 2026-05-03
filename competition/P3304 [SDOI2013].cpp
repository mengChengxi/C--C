#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair
vector<vector<pair<int,int>>> tree;
int maxn;
int overlap;
int maxni;
int longedge;
pair<int,int> maxdis(int n,int fa){
    if(tree[n].size()==0){
        return {0,0};
    }
    int maxx=0;
    int maxi=-1; // 微调：初始化为-1更安全，防止把第0个子节点误判掉
    int secondm=0;
    int dis_to_diverge=0;
    int second_dis_to_diverge=0;

    // 【修复 Bug 2】：开一个数组把子节点的计算结果存下来，坚决不重复算
    vector<pair<int, int>> child_res(tree[n].size());

    int maxcount=1;
    // 第一遍遍历：找最大值
    for(int i=0; i<tree[n].size(); i++){
        if(tree[n][i].first==fa){
            continue;
        }
        
        // 关键：在这里只算一次，存起来！
        child_res[i] = maxdis(tree[n][i].first, n); 
        int cur_val = child_res[i].first + tree[n][i].second;

        if(maxx == cur_val){
            dis_to_diverge=0;
            maxcount++;
        }else if(maxx < cur_val){
            dis_to_diverge = child_res[i].second + 1;
            maxx = cur_val;
            maxi = i;
            maxcount=1;
        }
    }
    
    
    // 第二遍遍历：找次大值
    for(int i=0; i<tree[n].size(); i++){
        if(tree[n][i].first==fa){
            continue;
        }
        if(i!=maxi){
            // 直接用刚才存好的结果
            int cur_val = child_res[i].first + tree[n][i].second;
            if(cur_val==secondm){
                second_dis_to_diverge=0;
            }else if(secondm < cur_val){
                second_dis_to_diverge = child_res[i].second + 1;
                secondm = cur_val;
            }
        }
    }
    
    
    // 你的原版核心逻辑：更新全局最大直径和重叠边数
    if(maxn < secondm+maxx){
        if(maxcount==2){
            longedge=second_dis_to_diverge+dis_to_diverge;
            overlap=second_dis_to_diverge+child_res[maxi].second + 1;
            
        }else{
            longedge=dis_to_diverge;
            overlap=second_dis_to_diverge+dis_to_diverge;
        }
        maxn=secondm+maxx;
        maxni=n;
        
        
    }else if(maxn == secondm+maxx){
        overlap-=longedge;
        if(maxcount==2){
            longedge=second_dis_to_diverge+dis_to_diverge;
            //overlap=second_dis_to_diverge+child_res[maxi].second + 1;
            
        }else{
            longedge=dis_to_diverge;
            //overlap=second_dis_to_diverge+dis_to_diverge;
        }
        maxn=secondm+maxx;
        maxni=n;

    }
    
    return {maxx,dis_to_diverge};
}

void solve() {
    int t;
    cin>>t;
    // 【修复 Bug 1】：题目节点从 1 到 t，必须分配 t+1 的空间
    tree.assign(t + 1, vector<pair<int,int>>());
    
    for(int i=1; i<t; i++){
        int from, to, dis;
        cin>>from>>to>>dis;
        tree[from].push_back({to,dis});
        tree[to].push_back({from,dis});
    }
    
    // 养成好习惯：全局变量在多组测试数据时最好手动清零
    maxn = 0; 
    overlap = 0;
    
    maxdis(1,0);

    cout<<maxn<<endl;
    cout<<overlap<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}