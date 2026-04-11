#include <bits/stdc++.h>

using namespace std;

int n, x, latest;

int main() {
    cin >> n >> x;
    for (int i = 0; i <= n; i ++ ) {
        int a; cin >> a;
        if (i == 0 || abs(a - latest) >= x) {
            latest = a;
            cout << i << ' ' << a << '\n';
        }
    }
    return 0;
}