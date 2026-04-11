#include <bits/stdc++.h>

using namespace std;

bool flg = true;
int n;
string s;

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] != 'o') flg = false;
        if (!flg) cout << s[i];
    } 
    return 0;
}