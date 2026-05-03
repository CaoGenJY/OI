#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5, maxd = 1e7 + 7;

int n;
int vis[maxn];
int dist[maxn], d_cnt;  //收集子树中的节点到当前根的距离
bool has_dist[maxd];
int q[maxn], q_cnt;     //用于清空has_dist
int m, query[maxn], ans[maxn];   //离线记录答案

struct Edge {
    int to, w;
};
vector<Edge> to[maxn];

int mx[maxn], sz[maxn], minn = 0x3f3f3f3f, zx = 0, total;

void get_zx(int u, int fa) {
    sz[u] = 1; mx[u] = 0;
    for (const auto &e : to[u]) {
        int v = e.to;
        if (v == fa || vis[v]) continue;
        get_zx(v, u);
        sz[u] += sz[v];
        mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], total - mx[u]);
    if (!zx || mx[u] < minn) {
        zx = u;
        minn = mx[u];
    }
}

void get_dist(int u, int fa, int d) {
    if (d > 1e7) return;
    dist[++d_cnt] = d;
    for (const auto &e : to[u]) {
        int v = e.to, w = e.w;
        if (v == fa || vis[v]) continue;
        get_dist(v, u, d + w);
    }
}

void calc(int u) {
    q_cnt = 0;
    has_dist[0] = true; q[++q_cnt] = 0;
    for (const auto &e : to[u]) {
        int v = e.to, w = e.w;
        if (vis[v]) continue;
        d_cnt = 0;
        get_dist(v, u, e.w);
        for (int i = 1; i <= d_cnt; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (query[j] >= dist[i] && has_dist[query[j] - dist[i]]) {
                    ans[j] = true;
                }
            }
        }
        for (int i = 1; i <= d_cnt; ++i) {
            if (!has_dist[dist[i]]) {
                has_dist[dist[i]] = true;
                q[++q_cnt] = dist[i];
            }
        }
    }
    for (int i = 1; i <= q_cnt; ++i) {
        has_dist[q[i]] = false;
    }
}

void solve(int u) {
    vis[u] = true;
    calc(u);
    for (const auto &e : to[u]) {
        int v = e.to, w = e.w;
        if (vis[v]) continue;
        total = sz[v];
        zx = 0;
        minn = 0x3f3f3f3f;
        get_zx(v, 0);
        solve(zx);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        to[u].push_back({v, w});
        to[v].push_back({u, w});
    }
    for (int i = 1; i <= m; ++i) {
        cin >> query[i];
    }
    total = n; zx = 0; get_zx(1, 0);
    solve(zx);
    for (int i = 1; i <= m; ++i) {
        if (ans[i]) {
            cout << "AYE\n";
        } else {
            cout << "NAY\n";
        }
    }
    return 0;
}