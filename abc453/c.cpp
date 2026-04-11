#include <bits/stdc++.h>

using namespace std;

const int maxn = 25;
int n, ans = 0;
int a[maxn];

void dfs(int u, double pos, int now) {
    if (u == n + 1) {
        ans = max(ans, now);
        return ;
    }
    if ((pos + a[u]) * pos <= 0) dfs(u + 1, pos + a[u], now + 1);
    else dfs(u + 1, pos + a[u], now);
    if ((pos - a[u]) * pos <= 0) dfs(u + 1, pos - a[u], now + 1);
    else dfs(u + 1, pos - a[u], now);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    dfs(0, 0.5, 0);
    cout << ans;
    return 0;
}