#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

// ==============================================================================
// 业务逻辑区：换题时只需要修改这里的结构体和函数
// ==============================================================================

// 1. 定义节点信息 (Info)
// 这里我们同时维护“区间和”、“区间最大值”以及“区间长度”
struct Info {
    
    long long max_val = -1e18; // 极小值
   

    // 默认构造
    Info() {}
    // 单点初始化的构造
    Info(long long val) : max_val(val){}

    // 2. 信息的合并：即 push_up 的本质
    // 定义两个子节点合并成父节点时的逻辑
    friend Info operator+(const Info& a, const Info& b) {
        Info c;
        c.max_val = max(a.max_val, b.max_val);
        return c;
    }
};

// 3. 定义懒惰标记 (Tag)
struct Tag {
    long long add = 0;
    long long target = INF;
    
    // 判断当前节点是否有标记需要下放
    bool has_tag() const {
        return add != 0 || target!=INF;
    }
    
    // 清空标记
    void clear() {
        add = 0;
        target =INF;
    }
};

// 4. 定义标记的作用逻辑 (Apply)
// 逻辑 A: 一个 Tag 作用到一个 Info 上，Info 会怎么变化？
void apply(Info& info, const Tag& tag) {
    if (!tag.has_tag()) return;
        if(tag.target==INF){
            info.max_val += tag.add; 
        }else{
            info.max_val=tag.target+tag.add;
        }

           // 区间最大值直接增加 tag
    
}

// 逻辑 B: 一个新的 Tag 作用到一个旧的 Tag 上（标记叠加），Tag 会怎么变化？
void apply(Tag& old_tag, const Tag& new_tag) {
    if(new_tag.target==INF){
        old_tag.add += new_tag.add;
    }else{
        old_tag.add=new_tag.add;   
        old_tag.target=new_tag.target;
    }
    
}


// ==============================================================================
// 核心框架区：写好一次，永远不用修改的代码（可以直接折叠）
// ==============================================================================

template<class Info, class Tag>
class LazySegmentTree {
private:
    int n;
    vector<Info> info;
    vector<Tag> tag;

    void push_up(int p) {
        // 直接利用我们重载的 + 运算符
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void apply_node(int p, const Tag& v) {
        apply(info[p], v); // 更新信息
        apply(tag[p], v);  // 叠加标记
    }

    void push_down(int p) {
        if (tag[p].has_tag()) {
            apply_node(2 * p, tag[p]);
            apply_node(2 * p + 1, tag[p]);
            tag[p].clear();
        }
    }

    void build(int p, int l, int r, const vector<Info>& init_info) {
        if (l == r) {
            info[p] = init_info[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * p, l, m, init_info);
        build(2 * p + 1, m + 1, r, init_info);
        push_up(p);
    }

    void modify(int p, int l, int r, int ql, int qr, const Tag& v) {
        if (ql <= l && r <= qr) {
            apply_node(p, v);
            return;
        }
        push_down(p);
        int m = (l + r) / 2;
        if (ql <= m) modify(2 * p, l, m, ql, qr, v);
        if (qr > m) modify(2 * p + 1, m + 1, r, ql, qr, v);
        push_up(p);
    }

    Info query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return info[p];
        }
        push_down(p);
        int m = (l + r) / 2;
        // 严格划分区间，避免产生空 Info 参与计算导致默认极小值溢出
        if (qr <= m) return query(2 * p, l, m, ql, qr);
        if (ql > m) return query(2 * p + 1, m + 1, r, ql, qr);
        return query(2 * p, l, m, ql, qr) + query(2 * p + 1, m + 1, r, ql, qr);
    }

public:
    LazySegmentTree(const vector<Info>& init_info) {
        n = init_info.size();
        info.assign(4 * n, Info());
        tag.assign(4 * n, Tag());
        if (n > 0) build(1, 0, n - 1, init_info);
    }

    void modify(int l, int r, const Tag& v) {
        if (l <= r) modify(1, 0, n - 1, l, r, v);
    }

    Info query(int l, int r) {
        if (l <= r) return query(1, 0, n - 1, l, r);
        return Info();
    }
};

// ==============================================================================
// 示例用法
// ==============================================================================

int sample() {
    // 初始数组 {1, 5, 3, 4, 2}
    vector<long long> arr = {1, 5, 3, 4, 2};
    
    // 将普通数组转化为 Info 结构体数组
    vector<Info> init_info(arr.size());
    for (size_t i = 0; i < arr.size(); ++i) {
        init_info[i] = Info(arr[i]);
    }

    // 实例化泛型线段树
    LazySegmentTree<Info, Tag> st(init_info);

    // 查询初始区间 [1, 3] 
    Info res1 = st.query(1, 3);
    cout << "初始区间 [1, 3] 的最大值: " << res1.max_val << endl; // 输出 5
    //cout << "初始区间 [1, 3] 的总和: " << res1.sum << endl;       // 输出 12

    // 对区间 [1, 3] 增加 2
    st.modify(1, 3, Tag{2}); // 数组变为 {1, 7, 5, 6, 2}

    // 查询修改后的区间 [1, 3]
    Info res2 = st.query(1, 3);
    cout << "修改后区间 [1, 3] 的最大值: " << res2.max_val << endl; // 输出 7
   // cout << "修改后区间 [1, 3] 的总和: " << res2.sum << endl;       // 输出 18

    return 0;
}

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int tt;
        cin>>tt;
        arr[i]=tt;
    }
    vector<Info> init_info(arr.size());
    for (size_t i = 0; i < arr.size(); ++i) {
        init_info[i] = Info(arr[i]);
    }

    // 实例化泛型线段树
    LazySegmentTree<Info, Tag> st(init_info);

    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int l,r, x;
            cin>>l>>r>>x;
            st.modify(l-1, r-1, Tag{0,x});
        } else if(op==2){
            int l,r, x;
            cin>>l>>r>>x;
            st.modify(l-1, r-1, Tag{x,INF});
        }else{
            int l,r;
            cin>>l>>r;
            Info res2 = st.query(l-1, r-1);
            cout << res2.max_val << endl; // 输出 7
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


const int MAXN = 100005;
//TODO 根据题意建立更多数组
long long sum[MAXN << 2], addi[MAXN << 2], arr[MAXN];

#define ls (i << 1)
#define rs (i << 1 | 1)

// 更新父节点
inline void up(int i) { sum[i] = sum[ls] + sum[rs]; }//TODO 合并子节点

// 打懒标记并更新sum
inline void lazy_tag(long long jv, int len, int i) {
    //TODO根据维护值的特点修改逻辑
    addi[i] += jv; 
    sum[i] += jv * len; 
}

// 下传标记
inline void down(int l, int r, int i) {
    if (addi[i] && l != r) { //TODO (0可能是合法值)
        int mid = (l + r) >> 1;
        lazy_tag(addi[i], mid - l + 1, ls);
        lazy_tag(addi[i], r - mid, rs);
        addi[i] = 0; //TODO 清空对应标记
    }
}

// 建树
void build(int l, int r, int i = 1) {
    //TODO 初始标记可能不是0
    addi[i] = 0;
    if (l == r) { sum[i] = arr[l]; return; }//TODO
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid + 1, r, rs);
    up(i);
}

// 区间加法
void add(int jl, int jr, long long jv, int l, int r, int i = 1) {
    if (jl <= l && jr >= r) { lazy_tag(jv, r - l + 1, i); return; }
    down(l, r, i);
    int mid = (l + r) >> 1;
    if (jl <= mid) add(jl, jr, jv, l, mid, ls);
    if (jr > mid)  add(jl, jr, jv, mid + 1, r, rs);
    up(i);
}

// 区间查询
long long query(int ql, int qr, int l, int r, int i = 1) {
    // TODO: ans 的初始化值 (求和为 0, 求最大值为 -INF, 求最小值为 INF)
    if (ql <= l && qr >= r) return sum[i];
    down(l, r, i);
    long long ans = 0; int mid = (l + r) >> 1; 
    // TODO: 查询合并逻辑 (ans += ... / ans = max(ans, ...))
    if (ql <= mid) ans += query(ql, qr, l, mid, ls);
    if (qr > mid)  ans += query(ql, qr, mid + 1, r, rs);
    return ans;
}