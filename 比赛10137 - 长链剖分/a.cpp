#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 6;
vector<int> to[maxn];

int len[maxn], son[maxn];
//  深度        长儿子编号
int pool[maxn], *now = pool;
int *f[maxn], ans[maxn];
//  f[i][j]代表从i节点往下j的节点个数
//  ans[i]代表使f[i][j]最大的最小的j

void dfs1(int u, int fa) {
    len[u] = 1;
    for (const auto &v : to[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        if (len[u] < len[v] + 1) {
            son[u] = v;
            len[u] = len[v] + 1;
        }        
    }
}

void dfs2(int u, int fa) {
    f[u][0] = 1;
    if (son[u]) {
        f[son[u]] = f[u] + 1;
        dfs2(son[u], u);
        ans[u] = ans[son[u]] + 1;
    }
    if (f[u][0] >= f[u][ans[u]]) {
        ans[u] = 0;
    }
    for (const auto &v : to[u]) {
        if (v == fa || v == son[u]) continue;
        f[v] = now;
        now += len[v];
        dfs2(v, u);
        for (int j = 0; j < len[v]; ++j) {
            f[u][j + 1] += f[v][j];
            if (f[u][j + 1] > f[u][ans[u]]) {
                ans[u] = j + 1;
            } else if(f[u][j + 1] == f[u][ans[u]] && j + 1 < ans[u]) {
                ans[u] = j + 1;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        to[u].push_back(v); to[v].push_back(u);
    }
    dfs1(1, 0);
    f[1] = now;
    now += len[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}