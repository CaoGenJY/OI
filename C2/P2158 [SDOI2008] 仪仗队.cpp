#include <bits/stdc++.h>
namespace nms {
    const int N = 1e6+6;
    int n, phi[N];
    void euler() {
        for (int i = 2; i <= N - 5; ++i) phi[i] = i;
        for (int i = 2; i <= N - 5; ++i) {
            if (phi[i] == i) {
                for (int j = i; j <= N - 5; j += i) {
                    phi[j] = phi[j] / i * (i - 1);
                }
            }
        }
    }
    void solve() {
        if (n == 1) {
            puts("0");
            exit(0);
        }
        int ans = 0;
        for (int i = 2; i < n; ++i) ans += phi[i];
        printf("%d\n", ans * 2 + 3);
    }
}
using namespace nms;
int main() {
    scanf("%d", &n);
    euler();
    solve();
    return 0;
}