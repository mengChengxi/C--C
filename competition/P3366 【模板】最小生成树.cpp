#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return; // 容错处理

    // 规范的建图方式
    vector<vector<pair<int, int>>> g(n + 1);
    vector<bool> ifin(n + 1, false);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    // 优先队列：默认大根堆，我们需要小根堆，所以用 greater
    // pair 中第一个元素存边权(z)，第二个元素存目标节点(y)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int sum = 0;
    int count = 0; // 记录加入树的节点数，判断图是否连通

    // 从节点 1 开始
    pq.push({0, 1}); // 到节点1的距离为0

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        // 如果该节点已经在生成树中，跳过（相当于你的 ifin 判断）
        if (ifin[u]) continue;

        // 将节点加入生成树
        ifin[u] = true;
        sum += weight;
        count++;

        // 遍历该节点的所有邻居
        for (auto edge : g[u]) {
            int v = edge.first;
            int w = edge.second;
            // 如果邻居还没在树中，将边放入优先队列候选
            if (!ifin[v]) {
                pq.push({w, v});
            }
        }
    }

    // 判断是否所有的点都连通了
    if (count == n) {
        cout << sum << "\n";
    } else {
        cout << "orz"; // 根据实际题目需求，可能输出 -1 等
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}