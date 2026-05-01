#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1e5 + 5;

ll d[64];

void insert(ll x) {
    for (int i = 60; i >= 0; --i) {
        if (!(x >> i)) continue;
        if (!d[i]) {
            d[i] = x;
            return;
        }
        else x ^= d[i];
    }
    return;
}

int n, m;
struct Edge {
    int to;
    ll w;
};
vector<Edge> to[maxn];

bool vis[maxn];
ll dis[maxn];

void dfs(int u) {
    vis[u] = true;
    for (const auto &v : to[u]) {
        if(vis[v.to]) {
            insert(dis[u] ^ dis[v.to] ^ v.w);
        } else {
            dis[v.to] = dis[u] ^ v.w;
            dfs(v.to);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        to[u].push_back({v, w});
        to[v].push_back({u, w});
    }
    dfs(1);
    ll ans = dis[n];
    for (int i = 60; i >= 0; --i) {
        if ((ans ^ d[i]) > ans) ans ^= d[i];
    }
    cout << ans << '\n';
    return 0;
}