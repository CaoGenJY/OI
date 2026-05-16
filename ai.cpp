#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 40005;

struct Edge {
    int to, weight;
};

vector<Edge> g[MAXN];
int n, k;
long long ans;

// 用于寻找重心的变量
int siz[MAXN], max_part[MAXN];
bool vis[MAXN];
int total_nodes, root;

// 存储当前连通块或子树中的距离
int dist[MAXN], d_cnt;

// 1. 寻找重心
void get_root(int u, int fa) {
    siz[u] = 1;
    max_part[u] = 0;
    for (const auto& edge : g[u]) {
        int v = edge.to;
        if (v == fa || vis[v]) continue;
        get_root(v, u);
        siz[u] += siz[v];
        max_part[u] = max(max_part[u], siz[v]);
    }
    max_part[u] = max(max_part[u], total_nodes - siz[u]);
    if (max_part[u] < max_part[root]) {
        root = u;
    }
}

// 2. 收集距离
void get_dist(int u, int fa, int d) {
    dist[++d_cnt] = d;
    for (const auto& edge : g[u]) {
        int v = edge.to;
        if (v == fa || vis[v]) continue;
        get_dist(v, u, d + edge.weight);
    }
}

// 3. 计算距离小于等于 k 的点对数（双指针）
long long calc(int u, int init_d) {
    d_cnt = 0;
    get_dist(u, 0, init_d);
    sort(dist + 1, dist + d_cnt + 1);
    
    long long res = 0;
    int l = 1, r = d_cnt;
    while (l < r) {
        if (dist[l] + dist[r] <= k) {
            res += (r - l);
            l++;
        } else {
            r--;
        }
    }
    return res;
}

// 4. 点分治主函数
void divide(int u) {
    // 计算当前整体连通块的贡献
    ans += calc(u, 0);
    vis[u] = true;
    
    for (const auto& edge : g[u]) {
        int v = edge.to;
        if (vis[v]) continue;
        
        // 容斥：减去同一棵子树内不经过根节点的重复统计
        ans -= calc(v, edge.weight);
        
        // 递归处理子树，先求出子树的重心
        total_nodes = siz[v];
        root = 0;
        get_root(v, 0);
        divide(root);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cin >> k;
    
    // 初始化寻找全局重心
    max_part[0] = n + 1;
    total_nodes = n;
    root = 0;
    get_root(1, 0);
    
    // 开始点分治
    divide(root);
    
    cout << ans << "\n";
    
    return 0;
}