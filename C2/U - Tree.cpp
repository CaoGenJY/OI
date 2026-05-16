#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 4e4 + 4;

struct Edge {
    int to, w;
};
vector<Edge> to[maxn];

int n, k;

int siz[maxn], mx[maxn];
bool vis[maxn];
int tot, root;

int dcnt, dis[maxn];

ll ans = 0;

void get_root(int u, int fa) {
    siz[u] = 1; mx[u] = 0;
    for (const auto &e : to[u]) {
        int v = e.to;
        if (v == fa || vis[v]) continue;
        get_root(v, u);
        siz[u] += siz[v];
        mx[u] = max(mx[u], siz[v]);
    }
    mx[u] = max(mx[u], tot - siz[u]);
    if (mx[u] < mx[root]) {
        root = u;
    }
}

void get_dist(int u, int fa, int d) {
    dis[++dcnt] = d;
    for (const auto &e : to[u]) {
        int v = e.to;
        if (v == fa || vis[v]) continue;
        get_dist(v, u, d + e.w);
    }
}

ll calc(int u, int init) {
    dcnt = 0;
    get_dist(u, 0, init);
    sort(dis + 1, dis + dcnt + 1);
    ll res = 0;
    int l = 1, r = dcnt;
    while (l < r) {
        if (dis[l] + dis[r] <= k) {
            res += (r - l);
            l++;
        } else {
            r--;
        }
    }
    return res;
}

void divide(int u) {
    ans += calc(u, 0);
    vis[u] = true;
    for (const auto &e : to[u]) {
        int v = e.to;
        if (vis[v]) continue;
        ans -= calc(v, e.w);
        tot = siz[v];
        root = 0;
        get_root(v, 0);
        divide(root);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        to[u].push_back({v, w});
        to[v].push_back({u, w});
    }
    cin >> k;
    mx[0] = 0x3f3f3f3f;
    tot = n;
    root = 0;
    get_root(1, 0);
    divide(root);
    cout << ans << '\n';
    return 0;
}