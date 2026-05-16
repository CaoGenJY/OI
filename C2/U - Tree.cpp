#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5, maxd = 1e7 + 7;

int n, k, ans = 0;
int vis[maxn];
int dist[maxn], d_cnt;  //收集子树中的节点到当前根的距离
int q[maxn], q_cnt;     //用于清空has_dist

struct Edge {
    int to, w;
};
vector<Edge> to[maxn];

int mx[maxn], sz[maxn], minn = 0x3f3f3f3f, zx = 0, total;

struct Bit {
    int tr[maxn];
    int lowbit(int x) {return x & (-x);}
    void add(int pos, int x) {for (; pos <= n; pos += lowbit(pos)) tr[pos] += x;}
    int query(int pos) {int ret = 0; for (; pos > 0; pos -= lowbit(pos)) ret += tr[pos]; return ret;}
} bit;

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
    bit.add(0, 1); q[++q_cnt] = 0;
    for (const auto &e : to[u]) {
        int v = e.to;
        if (vis[v]) continue;
        d_cnt = 0;
        get_dist(v, u, e.w);
        for (int i = 1; i <= d_cnt; ++i) {
            ans += bit.query(k - dist[i]);
        }
        for (int i = 1; i <= d_cnt; ++i) {
            if (!(bit.query(dist[i]) - bit.query(dist[i] - 1))) {
                bit.add(dist[i], 1);
                q[++q_cnt] = dist[i];
            }
        }
    }
    for (int i = 1; i <= q_cnt; ++i) {
        int tmp = bit.query(q[i]) - bit.query(q[i] - 1);
        bit.add(q[i], -tmp);
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
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        to[u].push_back({v, w});
        to[v].push_back({u, w});
    }
    cin >> k;
    total = n; zx = 0; get_zx(1, 0);
    solve(zx);
    cout << ans << '\n';
    return 0;
}