#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, tot, qcnt;
int ans[maxn];
struct node {
    int l, r, k, type, id, val;
}q[maxn * 3], q1[maxn * 3], q2[maxn * 3];
vector<int> nums;

int tr[maxn << 2];
int lowbit(int x) {
    return x & (-x);
}

int add(int pos, int x) {
    for (int i = pos; i <= n; i += lowbit(i)) {
        tr[i] += x;
    }
}

int query(int pos) {
    int ret = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) {
        ret += tr[i];
    }
    return ret;
}

void solve(int ql, int qr, int l, int r) {
    if (ql > qr) return;
    if (l == r) {
        for (int i = ql; i <= ql; i ++ ) {
            if (q[i].type == 2) {
                ans[q[i].id] = nums[l - 1];
            }
        }
        return;
    }
    int mid = l + r >> 1;
    int t1 = 0, t2 = 0;
    for (int i = ql; i <= qr; i ++ ) {
        if (q[i].type == 1) {
            if (q[i].val <= mid) {
                add(q[i].l, q[i].k);
                q1[ ++ t1] = q[i];
            } else {
                q2[ ++ t2] = q[i];
            } 
        } else {
            int cnt = query(q[i].r) - query(q[i].l - 1);
            if (q[i].k <= cnt) {
                q1[ ++ t1] = q[i];
            } else {
                q[i].k -= cnt;
                q2[ ++ t2] = q[i];
            }
        }
    }
    for (int i = 1; i <= t1; i ++ ) {
        if (q1[i].type == 1) add(q1[i].l, -q1[i].k);
    }
    for (int i = 1; i <= t1; i ++ ) {
        q[ql + i - 1] = q1[i];
    }
    for (int i = 1; i <= t2; i ++ ) {
        q[ql + t1 + i - 1] = q2[i]; 
    }
    solve(ql, ql + t1 - 1, l, mid);
    solve(ql + t1, qr, mid + 1, r);
}


int main() {

}