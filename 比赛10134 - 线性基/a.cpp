#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 55, maxb = 65;
int n;
ll a[maxn], d[maxb];

void insert(ll x) {
    for (int i = 60; i >= 0; --i) {
        if (!(x >> i)) continue;
        if (!d[i]) {
            d[i] = x;
            return;
        }
        else x ^= d[i];
    }
    return;
}

ll get_mx() {
    ll ans = 0;
    for (int i = 60; i >= 0; --i) {
        if ((ans ^ d[i]) > ans) ans ^= d[i];
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        insert(a[i]);
    }
    cout << get_mx();
    return 0;
}