//
// Created by caogenjy on 2026/3/21.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int maxn = 3e6 + 6, p = 998244353, g = 3, gi = 332748118;
ll ksm(ll a, ll k) {
    ll ret = 1;
    while(k) {
        if (k & 1) ret = ret * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return ret;
}
int rev[maxn];
void init(int lim, int k) {
    for (int i = 1; i <= lim; i ++ ) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }
}
void ntt(ll *a, int n, int flg) {
    for (int i = 0; i < n; i ++ ) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    for (int mid = 1; mid < n; mid <<= 1) {
        ll gn = ksm(flg == 1 ? g : gi, (p - 1) / (mid << 1));
        for (int i = 0; i < n; i += (mid << 1)) {
            ll now = 1;
            for (int j = i; j < i + mid; j ++ ) {
                ll x = a[j] % p, y = now * a[j + mid] % p;
                a[j] = (x + y) % p;
                a[j + mid] = (x - y + p) % p;
                now = now * gn % p;
            }
        }
    }
    if (flg == -1) {
        ll ni = ksm(n, p - 2);
        for (int i = 0; i < n; i ++ ) {
            a[i] = a[i] * ni % p;
        }
    }
}
int n, m;
ll a[maxn], b[maxn];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("0in.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; i ++ ) {
		cin >> a[i];
	}
	for (int i = 0; i <= m; i ++ ) {
		cin >> b[i];
	}
	int lmt = 1, k = 0;
	while (lmt <= (n + m)) {
		lmt <<= 1;
		k ++ ;
	}
	init(lmt, k);
	ntt(a, lmt, 1);
	ntt(b, lmt, 1);
	for (int i = 0; i < lmt; i ++ ) {
		a[i] = a[i] * b[i] % p;
	}
	ntt(a, lmt, -1);
	for (int i = 0; i <= n + m; i ++ ) {
		cout << a[i] << ' ';
	}
    return 0;
}
