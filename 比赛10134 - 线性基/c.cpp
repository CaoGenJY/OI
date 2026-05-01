#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1005, maxb = 65;
int n;
ll d[maxb];
struct node {
    ll a, c;
} a[maxn];


bool insert(ll x) {
    for (int i = 60; i >= 0; --i) {
        if (!(x >> i)) continue;
        if (!d[i]) {
            d[i] = x;
            return true;
        }
        else x ^= d[i];
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].a >> a[i].c;
    }
    sort(a + 1, a + n + 1, [&](node a, node b) {
        return a.c > b.c;
    });
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (insert(a[i].a)) ans += a[i].c;
    }
    cout << ans;
    return 0;
}