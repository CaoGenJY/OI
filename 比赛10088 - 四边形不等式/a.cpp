#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int n;
int a[maxn], f[maxn][maxn], s[maxn][maxn], sum[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = 0;
        s[i][i] = i;
    }
    for (int len = 2; len <= n; len ++ ) {
        for (int i = 1; i + len - 1 <= n; i ++ ) {
            int j = i + len - 1;
            f[i][j] = 0x3f3f3f3f;
            int l = s[i][j - 1], r = s[i + 1][j];
            for (int k = l; k <= r && k < j; k ++ ) {
                int cost = f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1];
                if (f[i][j] > cost) {
                    f[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << f[1][n];
    return 0;
}