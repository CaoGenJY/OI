#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

// 邻接表
vector<int> adj[MAXN];
// len: 向下延伸的最长长度, son: 长儿子, ans: 最终每个点的答案偏移量
int len[MAXN], son[MAXN], ans[MAXN];
// pool: 全局内存池, f: 指向每个点 DP 数组起始位置的指针
int pool[MAXN], *f[MAXN], *now = pool;

// 第一遍 DFS：找长儿子并计算每个点向下的最大深度
void dfs_son(int u, int fa) {
    len[u] = 1; 
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs_son(v, u);
        if (len[v] + 1 > len[u]) {
            len[u] = len[v] + 1;
            son[u] = v; // 谁向下伸得最深，谁就是长儿子
        }
    }
}

// 第二遍 DFS：实际的 DP 转移
void dfs_solve(int u, int fa) {
    f[u][0] = 1; // 距离为 0 的点（即 u 自己）初始为 1
    
    if (son[u]) {
        // 【关键】让长儿子的指针指向 f[u] 的下一个位置
        // 这样 f[son[u]][i] 就自动对应了 f[u][i+1]
        f[son[u]] = f[u] + 1;
        dfs_solve(son[u], u);
        
        // 继承长儿子的最佳答案偏移量，并 +1
        ans[u] = ans[son[u]] + 1;
    }

    // 检查：如果当前位置 (距离 0) 的人数 >= 长儿子反馈的最佳位置人数，则更新答案
    // 题目要求深度相同时取较小深度，所以这里是 >=
    if (f[u][0] >= f[u][ans[u]]) {
        ans[u] = 0;
    }

    for (int v : adj[u]) {
        if (v == fa || v == son[u]) continue;
        
        // 轻儿子需要重新分配一段独立内存（长链顶端）
        f[v] = now;
        now += len[v];
        
        dfs_solve(v, u);

        // 暴力合并轻儿子的信息
        for (int j = 0; j < len[v]; j++) {
            int dist_to_u = j + 1;
            f[u][dist_to_u] += f[v][j];
            
            // 更新当前节点 u 的最佳答案
            if (f[u][dist_to_u] > f[u][ans[u]]) {
                ans[u] = dist_to_u;
            } else if (f[u][dist_to_u] == f[u][ans[u]] && dist_to_u < ans[u]) {
                ans[u] = dist_to_u;
            }
        }
    }
}

int main() {
    // 优化 IO
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1. 预处理长儿子
    dfs_son(1, 0);

    // 2. 为根节点和初始长链分配内存
    f[1] = now;
    now += len[1];

    // 3. 递归求解
    dfs_solve(1, 0);

    // 4. 输出每个节点的答案
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}