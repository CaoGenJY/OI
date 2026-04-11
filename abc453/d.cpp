#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
int n, m, stx, sty;
char ch[maxn][maxn];

int dx[] = {-1, 1, 0, 0}; // 0:U, 1:D, 2:L, 3:R
int dy[] = {0, 0, -1, 1};
char dchar[] = {'U', 'D', 'L', 'R'};

struct node {
    int x, y, dir; 
};

struct Path {
    int x, y, dir;
    char move;
} pre[maxn][maxn][4];
bool vis[maxn][maxn][4]; 

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    if (!(cin >> n >> m)) return 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ch[i][j];
            if (ch[i][j] == 'S') stx = i, sty = j;
        }
    }
    queue<node> q;
    for (int i = 0; i < 4; i++) {
        int nkx = stx + dx[i], nky = sty + dy[i];
        if (nkx >= 1 && nkx <= n && nky >= 1 && nky <= m && ch[nkx][nky] != '#') {
            vis[nkx][nky][i] = true;
            pre[nkx][nky][i] = {stx, sty, -1, dchar[i]};
            q.push({nkx, nky, i});
        }
    }
    while (!q.empty()) {
        node kdr = q.front(); q.pop();
        if (ch[kdr.x][kdr.y] == 'G') {
            string res = "";
            int cx = kdr.x, cy = kdr.y, cd = kdr.dir;
            while (cx != stx || cy != sty) {
                Path p = pre[cx][cy][cd];
                res += p.move;
                cx = p.x; cy = p.y; cd = p.dir;
            }
            cout << "Yes\n";
            for (int i = (int)res.size() - 1; i >= 0; i -- ) cout << res[i];
            cout << '\n';
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            if (ch[kdr.x][kdr.y] == 'o' && i != kdr.dir) continue;
            if (ch[kdr.x][kdr.y] == 'x' && i == kdr.dir) continue;
            int nkx = kdr.x + dx[i], nky = kdr.y + dy[i];
            if (nkx >= 1 && nkx <= n && nky >= 1 && nky <= m && ch[nkx][nky] != '#') {
                if (!vis[nkx][nky][i]) {
                    vis[nkx][nky][i] = true;
                    pre[nkx][nky][i] = {kdr.x, kdr.y, kdr.dir, dchar[i]};
                    q.push({nkx, nky, i});
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}