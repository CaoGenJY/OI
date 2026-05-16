#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 3e5 + 5;

struct Edge {
    int to, w;
};
int n, m;
vector<Edge> to[maxn];
int f[maxn];
bool is[maxn];

void dfs(int u, int fa) {
    for (const auto &v : to[u]) {
        if (v.to == fa) continue;
        if (is[v.to]) {
            f[u] += v.w;
        } else {
            dfs(v.to, u);
            f[u] += min(v.w, f[v.to]);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v, w; cin >> u >> v >> w;
        to[u].push_back({v, w}); to[v].push_back({u, w});
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int x; cin >> x; is[x] = true;
    }
    dfs(1, 0);
    cout << f[1] << '\n';
    return 0;
}