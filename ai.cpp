#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
const int MAXK = 10000005; // 路径最大长度
const int INF = 1e9;

struct Edge {
    int to, weight;
};

vector<Edge> G[MAXN];
int n, m;
int query[105], ans[105];
int sz[MAXN], max_sz[MAXN], root, total_sz;
bool vis[MAXN]; // 标记节点是否作为重心被处理过
int dist[MAXN], d_cnt; // 存储当前子树所有节点到重心的距离
bool has_dist[MAXK]; // 标记之前子树中出现过的距离
int q[MAXN], q_cnt; // 暂存当前正在处理的子树距离，方便后续更新 has_dist

// --- 1. 寻找重心 ---
// 重心：最大子树的大小最小的点
void get_root(int u, int fa) {
    sz[u] = 1;
    max_sz[u] = 0;
    for (auto &e : G[u]) {
        if (e.to == fa || vis[e.to]) continue;
        get_root(e.to, u);
        sz[u] += sz[e.to];
        max_sz[u] = max(max_sz[u], sz[e.to]);
    }
    max_sz[u] = max(max_sz[u], total_sz - sz[u]);
    if (!root || max_sz[u] < max_sz[root]) root = u;
}

// --- 2. 收集距离 ---
// 递归收集当前子树中所有节点到分治中心的距离
void get_dist(int u, int fa, int d) {
    if (d > 1e7) return; // 题目给出的 k 最大 1e7，超过则无意义
    dist[++d_cnt] = d;
    for (auto &e : G[u]) {
        if (e.to == fa || vis[e.to]) continue;
        get_dist(e.to, u, d + e.weight);
    }
}

// --- 3. 处理当前重心 ---
void calc(int u) {
    q_cnt = 0;
    has_dist[0] = true; // 距离为0的路径（即重心本身）
    q[++q_cnt] = 0;

    for (auto &e : G[u]) {
        if (vis[e.to]) continue;
        d_cnt = 0;
        get_dist(e.to, u, e.weight); // 获取该子树所有点到u的距离

        // 尝试与之前子树的路径合并
        for (int i = 1; i <= d_cnt; ++i) {
            for (int k = 1; k <= m; ++k) {
                if (query[k] >= dist[i] && has_dist[query[k] - dist[i]]) {
                    ans[k] = true;
                }
            }
        }

        // 将当前子树的距离加入 has_dist，供后面的子树合并
        for (int i = 1; i <= d_cnt; ++i) {
            if (dist[i] < MAXK) {
                if (!has_dist[dist[i]]) {
                    has_dist[dist[i]] = true;
                    q[++q_cnt] = dist[i]; // 记录哪些位置变为了true，方便清空
                }
            }
        }
    }

    // --- 4. 清空 has_dist ---
    // 千万不要 memset，利用记录的 q 数组只清空修改过的地方
    for (int i = 1; i <= q_cnt; ++i) has_dist[q[i]] = false;
}

// --- 5. 分治主函数 ---
void solve(int u) {
    vis[u] = true;
    calc(u); // 处理经过当前重心 u 的所有路径
    for (auto &e : G[u]) {
        if (vis[e.to]) continue;
        // 递归处理子树，需要重新找子树的重心
        total_sz = sz[e.to];
        root = 0;
        get_root(e.to, u);
        solve(root);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    for (int i = 1; i <= m; ++i) cin >> query[i];

    // 初始化找全树重心
    total_sz = n;
    root = 0;
    get_root(1, 0);

    // 开始分治
    solve(root);

    for (int i = 1; i <= m; ++i) {
        cout << (ans[i] ? "AYE" : "NAY") << "\n";
    }

    return 0;
}