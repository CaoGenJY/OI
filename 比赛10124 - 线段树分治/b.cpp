#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 5;
int n, m, K;
bool ans[maxn];
struct edge {
    int u, v, l, r;
};
#define ve vector<edge>
int k = 0;
ve g;

//dsu begin
int fa[maxn];
bool dis[maxn];
void init() {
    for (int i = 1; i <= (n << 1); i ++ ) {
        fa[i] = i;
    }
}
int find(int x) {
    while (x != fa[x]) {
        k ^= dis[x];
        x = fa[x];
    }
    return x;
}
//dsu end

void dfs(int l, int r, ve & v) {
    ve v1, v2;
    int mid = (l + r) >> 1, ok = 1;
    queue<int> d;
    for (const auto &e : v) {
        if (e.l >= l && e.r <= r) {
            k = 0;
            int fu = find(e.u), fv = find(e.v);
            if (fu == fv) {
                if (!k) {
                    for (int i = l; i <= r; i ++ ) {
                        ans[i] = true;
                        ok = 0;
                        break;
                    }
                } else {
                    if (rand() & 1) swap(fu, fv);
                    fa[fu] = fv;
                    dis[fu] = k ^ 1;
                    d.push(fu);
                }
            }
        } else {
            if (e.l <= mid) v1.push_back(e);
            if (e.r > mid) v2.push_back(e);
        }
    }
    if (ok && l != r) {
        dfs(l, mid, v1);
        dfs(mid + 1, r, v2);
    }
    while (!d.empty()) {
        fa[d.front()] = d.front();
        dis[d.front()] = 0;
        d.pop();
    }
}

int main() {
    cin >> n >> m >> K;
    for (int i = 1; i <= m; i ++ ) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        g.push_back({u, v, l, r});
    }
    init();
    dfs(1, K, g);
    for (int i = 1; i <= K; i ++ ) {
        if (!ans[i]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}