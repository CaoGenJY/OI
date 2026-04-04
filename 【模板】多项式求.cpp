#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 4e5 + 5, p = 998244353, g = 3, gi = 332748118;
ll ksm(ll a, ll k) {
	ll ret = 1;
	while (k) {
		if (k & 1) ret = ret * a % p;
		a = a * a % p;
		k >>= 1;
	}
	return ret;
}
int rev[maxn];
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
void init(int lim, int k) {
    for (int i = 1; i <= lim; i ++ ) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }
}

ll tmp[maxn];
void poly_inv(int n, ll *a, ll *b) {
	if (n == 1) {
		b[0] = ksm(a[0], p - 2);
		return ;
	}
	poly_inv((n + 1) >> 1, a, b);
	ll lim = 1, k = 0;
	while (lim <= (n << 1)) {
		lim <<= 1;
		k ++ ;
	}
	init(lim, k);
	for (int i = 0; i < n; i ++ ) {
		tmp[i] = a[i];
	}
	for (int i = n; i <= lim; i ++ ) {
		tmp[i] = 0;
	}
	ntt(tmp, lim, 1);
	ntt(b, lim, 1);
	for (int i = 0; i <= lim; i ++ ) {
		b[i] = b[i] * (2 - tmp[i] * b[i] % p + p) % p;
	}
	ntt(b, lim, -1);
	for (int i = n; i <= lim; i ++ ) {
		b[i] = 0;
	}
	return ;
}
ll n;
ll a[maxn], b[maxn];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++ ) {
		cin >> a[i];
	}
	poly_inv(n, a, b);
	for (int i = 0; i < n; i ++ ) {
		cout << b[i] << ' ';
	}
	return 0;
}
