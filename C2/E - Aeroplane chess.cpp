#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;
int n, m;
int to[maxn];
double f[maxn];

void solve() {
    for (int i = 0; i <= n + 6; ++i) {
        f[i] = to[i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        to[u] = v;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (to[i]) {
            f[i] = f[to[i]];
            continue;
        } else {
            double tmp = 0;
            for (int j = 1; j <= 6; ++j) {
                tmp += f[min(i + j, n)];
            }
            f[i] = tmp / 6.0 + 1;
        }
    } 
    cout << fixed << setprecision(4) << f[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while (true) {
        cin >> n >> m;
        if (n || m) solve();
        else break;
    }
    return 0;
}