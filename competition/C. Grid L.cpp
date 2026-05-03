#include <bits/stdc++.h>
using namespace std;

using ld = long double;

static constexpr ld INF = 1e100L;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> is_red(n, 0), deg(n), ext_red(n, 0);
    for (int i = 0; i < n; ++i) {
        is_red[i] = (s[i] == '1');
        deg[i] = (int)g[i].size();
    }

    for (int u = 0; u < n; ++u) {
        if (!is_red[u]) {
            for (int v : g[u]) {
                ext_red[u] += is_red[v];
            }
        }
    }

    vector<int> vis(n, 0), parent(n, -2);
    vector<ld> dp0(n, INF), dp1(n, INF);
    ld answer = 0;

    for (int start = 0; start < n; ++start) {
        if (is_red[start] || vis[start]) {
            continue;
        }

        vector<int> order;
        order.push_back(start);
        vis[start] = 1;
        parent[start] = -1;

        for (int i = 0; i < (int)order.size(); ++i) {
            int u = order[i];
            for (int v : g[u]) {
                if (is_red[v] || v == parent[u]) {
                    continue;
                }
                vis[v] = 1;
                parent[v] = u;
                order.push_back(v);
            }
        }

        for (int i = (int)order.size() - 1; i >= 0; --i) {
            int u = order[i];
            ld base_sum = 0;
            vector<ld> delta;

            for (int v : g[u]) {
                if (is_red[v] || parent[v] != u) {
                    continue;
                }
                base_sum += dp1[v];
                if (dp0[v] < INF / 2) {
                    delta.push_back(dp0[v] - dp1[v]);
                }
            }

            sort(delta.begin(), delta.end());
            ld pref = 0;

            dp0[u] = INF;
            dp1[u] = INF;

            for (int k = 0; k <= (int)delta.size(); ++k) {
                if (ext_red[u] + k > 0) {
                    dp0[u] = min(dp0[u], base_sum + pref + (ld)deg[u] / (ext_red[u] + k));
                }
                dp1[u] = min(dp1[u], base_sum + pref + (ld)deg[u] / (ext_red[u] + 1 + k));
                if (k < (int)delta.size()) {
                    pref += delta[k];
                }
            }
        }

        answer += dp0[start];
    }

    cout << fixed << setprecision(15) << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
