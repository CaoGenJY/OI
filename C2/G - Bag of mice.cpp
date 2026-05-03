#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 3;
int n, m;
double f[maxn][maxn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        f[i][0] = 1;
    }
    for (double i = 1; i <= n; ++i) {
        for (double j = 1; j <= m; ++j) {
            f[(int)i][(int)j] = (double)i / (i + j);
            
            if (j >= 2) {
                double tmp = (double)j / (i + j) * (j - 1) / (i + j - 1);
                f[(int)i][(int)j] += tmp * i / (i + j - 2) * f[(int)i - 1][(int)j - 2];
                if (j >= 3) {
                    f[(int)i][(int)j] += tmp * (j - 2) / (i + j - 2) * f[(int)i][(int)j - 3];
                }
            }
        }
    }
    cout << fixed << setprecision(9) << f[n][m];
    return 0;
}