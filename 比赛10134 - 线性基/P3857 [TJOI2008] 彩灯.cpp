#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 55;
ll n, m, cnt = 0, tmp = 0;
ll d[maxn];

void insert(ll x) {
    for (int i = 50; i >= 0; --i) {
        if (!(x >> i)) continue;
        if (!d[i]) {
            d[i] = x;
            return;
        }
        else x ^= d[i];
    }
    return;
}

void rebuild() {
    for (int i = 50; i >= 0; --i) {
        if (!d[i]) continue;
        for (int j = i - 1; j >= 0; --j) {
            if ((d[i] >> j) & 1) d[i] ^= d[j]; 
        }
    }
    for (int i = 0; i <= 50; ++i) if (d[i]) cnt++;
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        tmp = 0;
        for (int j = 1; j <= n; ++j) {
            char st; cin >> st;
            if (st == 'O') {
                tmp |= (1ll << (n - j));
            }
        }
        insert(tmp);
    }
    rebuild();
    cout << (1ll << cnt) % 2008;
    return 0;
}