#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 3;
int n, m, k;
int a[maxn], b[maxn], f[15][maxn][maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i ++ ) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= k; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            for (int k = 1; k <= m; k ++ ) {
                if (a[j] > b[k]) {
                    f[i][j][k] = f[i - 1][j - 1][k - 1];
                }
            }
        }
        for (int j = 1; j <= n; j ++ ) {
            for (int k = 1; k <= m; k ++ ) {
                f[i][j][k] = f[i][j][k - 1];
            }
        }
        for (int j = 1; j <= n; j ++ ) {
            for (int k = 1; k <= m; k ++ ) {
                f[i][j][k] = f[i][j - 1][k];
            }
        }
    }
    cout << f[k][n][m];
    return 0;
}