#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 55, maxb = 64;
ll n, K, flg = false;
ll a[maxn], d[maxb];
vector<ll> v;

void insert(ll x) {
    for (int i = maxb - 1; i >= 0; --i) {
        if (!(x >> i)) continue;
        if (!d[i]) {
            d[i] = x;
            return;
        }
        else x ^= d[i];
    }
    flg = true;
    return;
}

void rebuild() {
    for (int i = maxb - 1; i >= 0; --i) {
        if (!d[i]) continue;
        for (int j = i - 1; j >= 0; --j) {
            if ((d[i] >> j) & 1) d[i] ^= d[j]; 
        }
    }
    v.clear();
    for (int i = 0; i < maxb; ++i) {
        if (d[i]) v.push_back(d[i]);
    }
    return;
}

ll get_kth(ll k) {
    if (flg) k--;
    if (!k) return 0;
    if (k >= (1ll << v.size())) return -1;
    ll ans = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        if ((k >> i) & 1) ans ^= v[i];
    }
    return ans;
}

int main() {
    cin >> n >> K;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        insert(a[i]);
    }
    rebuild();
    cout << get_kth(K);
    return 0;
}