#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define mkp make_pair

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> sorted_nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
        sorted_nums[i] = nums[i];
    }

    // 1. 确定全局中位数
    sort(sorted_nums.begin(), sorted_nums.end());
    int m = sorted_nums[n/2];

    int count = 0;
    int cur_sum = 0;

    // 2. 贪心划分
    for(int i=0; i<n; i++){
        // >= m 贡献 1, < m 贡献 -1
        if(nums[i] >= m) cur_sum++;
        else cur_sum--;

        // 只要当前段的“贡献”大于 0，它就是一个合法的中位数段
        // 贪心：一旦满足要求，立刻切断，保证段数最多
        if(cur_sum > 0) {
            count++;
            cur_sum = 0; 
        }
    }

    // 这里不需要处理剩余的 cur_sum，因为根据中位数定义，
    // 剩下的部分并入最后一段后，最后一段的 sum 依然会 > 0。
    cout << count << endl;
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
