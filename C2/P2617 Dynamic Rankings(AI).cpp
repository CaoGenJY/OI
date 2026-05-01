#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义操作结构体
struct Node {
    int l, r, k, type, id, val;
    // type: 1 表示修改操作（包含初始赋值），2 表示查询操作
    // id: 记录查询的原始编号，方便按顺序输出答案
    // val: 对于修改操作，表示数值；对于查询操作，不使用
};

const int MAXN = 200005;
Node q[MAXN * 3], q1[MAXN * 3], q2[MAXN * 3];
int a[MAXN], ans[MAXN], bit[MAXN];
int n, m, tot, query_cnt;
vector<int> nums; // 用于离散化

// 树状数组标准操作
inline int lowbit(int x) { return x & -x; }

void add(int x, int v) {
    for (; x <= n; x += lowbit(x)) bit[x] += v;
}

int query(int x) {
    int res = 0;
    for (; x > 0; x -= lowbit(x)) res += bit[x];
    return res;
}

/**
 * 整体二分核心函数
 * ql, qr: 当前处理的操作序列下标区间
 * L, R: 当前可能的数值范围（离散化后的索引）
 */
void solve(int ql, int qr, int L, int R) {
    if (ql > qr) return;
    
    // 边界条件：数值范围收敛到一个点
    if (L == R) {
        for (int i = ql; i <= qr; i++) {
            if (q[i].type == 2) ans[q[i].id] = nums[L - 1]; // 映射回原值
        }
        return;
    }

    int mid = (L + R) >> 1;
    int t1 = 0, t2 = 0;

    for (int i = ql; i <= qr; i++) {
        if (q[i].type == 1) {
            // 如果是修改操作，且数值落在左半部分 [L, mid]
            if (q[i].val <= mid) {
                add(q[i].l, q[i].k); // k 为权值（+1 或 -1）
                q1[++t1] = q[i];
            } else {
                q2[++t2] = q[i];
            }
        } else {
            // 如果是查询操作，计算当前区间内属于左半部分的个数
            int cnt = query(q[i].r) - query(q[i].l - 1);
            if (q[i].k <= cnt) {
                q1[++t1] = q[i];
            } else {
                q[i].k -= cnt; // 关键：减去左边的个数，在右边找剩余的第 k 大
                q2[++t2] = q[i];
            }
        }
    }

    // 撤销树状数组修改（清空以便后续逻辑使用，严禁 memset）
    for (int i = 1; i <= t1; i++) {
        if (q1[i].type == 1) add(q1[i].l, -q1[i].k);
    }

    // 将划分好的两组操作重新放回原数组
    for (int i = 1; i <= t1; i++) q[ql + i - 1] = q1[i];
    for (int i = 1; i <= t2; i++) q[ql + t1 + i - 1] = q2[i];

    // 递归处理左右区间
    solve(ql, ql + t1 - 1, L, mid);
    solve(ql + t1, qr, mid + 1, R);
}

int main() {
    // 优化 IO
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums.push_back(a[i]);
        // 初始状态看作是在位置 i 插入了 a[i]
        q[++tot] = {i, 0, 1, 1, 0, a[i]};
    }

    for (int i = 1; i <= m; i++) {
        char op;
        cin >> op;
        if (op == 'Q') {
            int l, r, k;
            cin >> l >> r >> k;
            q[++tot] = {l, r, k, 2, ++query_cnt, 0};
        } else {
            int pos, val;
            cin >> pos >> val;
            // 修改操作：先减掉旧值的贡献，再增加新值
            q[++tot] = {pos, 0, -1, 1, 0, a[pos]};
            a[pos] = val;
            q[++tot] = {pos, 0, 1, 1, 0, val};
            nums.push_back(val);
        }
    }

    // 离散化所有涉及到的数值
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    // 将所有操作中的 val 转换为离散化后的排名
    for (int i = 1; i <= tot; i++) {
        if (q[i].type == 1) {
            q[i].val = lower_bound(nums.begin(), nums.end(), q[i].val) - nums.begin() + 1;
        }
    }

    solve(1, tot, 1, nums.size());

    for (int i = 1; i <= query_cnt; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}