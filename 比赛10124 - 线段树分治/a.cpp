#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int n, m, k;
struct Edge {
    int u, v;
};

//sgt begin
struct Node {
    int u, v;
};
stack<Node> st;
vector<Edge> tree[maxn << 2];


void update(int node, int l, int r, int ql, int qr, Edge e) {
    if (ql > qr || ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        tree[node].push_back(e);
        return;
    }
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, ql, qr, e);
    update(node << 1 | 1, mid + 1, r, ql, qr, e);
}
//sgt end
//bcj begin
int fa[maxn], siz[maxn];
void init() {
    for (int i = 1; i <= n << 1; i ++ ) {
        fa[i] = i;
        siz[i] = 1;
    }
}
int find(int x) {
    while (x != fa[x]) x = fa[x];
    return x;
}
void merge(int x, int y) {
    x = find(x); y = find(y); if(x == y) return;
    if (siz[x] > siz[y]) swap(x, y);
    fa[x] = y; 
    siz[y] += siz[x];
    st.push({x, y});
}
//bcj end
void solve(int node, int l, int r) {
    bool ok = true;
    int lst = st.size();
    for (const auto &e : tree[node]) {
        int u = e.u, v = e.v;
        if (find(u) == find(v)) {
            for (int i = l; i <= r; i ++ ) cout << "No\n";
            ok = false;
            break;
        }
        merge(u, v + n);
        merge(v, u + n);
    }
    if (ok) {
        if (l == r) {
            cout << "Yes\n";
        } else {
            int mid = (l + r) >> 1;
            solve(node << 1, l, mid);
            solve(node << 1 | 1, mid + 1, r);
        }
    }
    while (st.size() > lst) {
        fa[st.top().u] = st.top().u;
        siz[st.top().v] -= siz[st.top().u];
        siz[st.top().u] = 1;
        st.pop();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    init();
    for (int i = 1; i <= m; i ++ ) {
        int u, v, l, r; cin >> u >> v >> l >> r;
        update(1, 1, k, l + 1, r, {u, v});
    }
    solve(1, 1, k);
    return 0;
}