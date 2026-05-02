#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;
int n, m;
vector<int> to[maxn];
double ans, p[maxn];

void dfs(int u, int fa, double length) {
    double out = 0;
    for (const auto &v : to[u]) if (v != fa) out++;
    if (!out) {
        cerr << u << ' ' << length << ' ' << p[u] << '\n';
        ans += length * p[u];
        return;
    }
    for (const auto &v : to[u]) {
        if (v == fa) continue;
        p[v] = p[u] / (out);
        dfs(v, u, length + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    p[1] = 1;
    dfs(1, 0, 0);
    cout << fixed << setprecision(15) << ans << '\n';
    return 0;
}