#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define ll long long

using namespace std;

const int maxn = 1e6 + 6;

struct node {
    ll l, w;
} a[maxn], b[maxn];
ll n, m;
ll dp[maxn];
ll hh = 1, tt = 0, q[maxn];

double slope(int i, int j) {
    return (double)(dp[i] - dp[j]) / (b[j + 1].l - b[i + 1].l);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i].l >> a[i].w;
    }
    sort(a + 1, a + n + 1, [](node x, node y){
        if (x.l == y.l) return x.w > y.w;
        return x.l > y.l;
    });
    m = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i].w > b[m].w) b[++ m] = a[i];
    }

    q[++ tt] = 0;
    for (int i = 1; i <= m; i ++ ) {
        while (hh < tt && slope(q[hh], q[hh + 1]) <= b[i].w) hh ++ ;
        dp[i] = dp[q[hh]] + b[i].w * b[q[hh] + 1].l;
        while (hh < tt && slope(q[tt - 1], q[tt]) >= slope(q[tt], i)) tt -- ;
        q[++ tt] = i;
    }
    cout << dp[m] << '\n';
    return 0;
}