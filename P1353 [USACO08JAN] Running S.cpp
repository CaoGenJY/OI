#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e4 + 4, maxm = 505;
int n, m;
int a[maxn], f[maxn][maxm];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j - 1] + a[i];
        }
        f[i][0] = f[i - 1][0];
        for (int j = 1; j < i; j ++ ) {
            f[i][0] = max(f[i][0], f[i - j][j]);
        }
    }
    cout << f[n][0];
    return 0;
}