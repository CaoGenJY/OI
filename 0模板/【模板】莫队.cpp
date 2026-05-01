#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5 + 5;
int n, m, k;
int a[maxn], bel[maxn];
ll res, c[maxn], ans[maxn];
struct Query {
    int l, r, id;
}q[maxn];

void add(int x) {
    res += 2 * c[a[x]] + 1;
    c[a[x]] ++ ;
}

void sub(int x) {
    res -= 2 * c[a[x]] - 1;
    c[a[x]] -- ;
}

bool cmp(Query x, Query y) {
    if(bel[x.l] == bel[y.l]) {
        return x.r < y.r;
    }
    return bel[x.l] < bel[y.l];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    int siz = sqrt(n);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        bel[i] = i/siz;
    }
    for (int i = 1; i <= m; i ++ ) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= m; i ++ ) {
        while (l > q[i].l) add(-- l);
        while (r < q[i].r) add(++ r);
        while (l < q[i].l) sub(l ++ );
        while (r > q[i].r) sub(r -- );
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= m; i ++ ) {
        cout << ans[i] << '\n';
    }
    return 0;
}