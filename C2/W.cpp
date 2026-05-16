#include <bits/stdc++.h>

using namespace std;

int to_ten(string s, int base) {
    int ret = 0, now = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        ret += (s[i] - '0') * now;
        now *= base;
    }
    return ret;
}

string to_three(int x) {
    string ret = "";
    while (x) {
        ret += to_string(x % 3);
        x /= 3;
    }
    return ret;
}

int main () {
    string two, three, tmp; cin >> two >> three;
    reverse(three.begin(), three.end());
    for (int i = 0; i < two.size(); ++i) {
        if (two[i] == '0') two[i] = '1';
        else two[i] = '0';
        int ten = to_ten(two, 2);
        tmp = to_three(ten);
        if (tmp.size() == three.size()) {
            int num = 0;
            for (int i = 0; i < tmp.size(); ++i) {
                if (tmp[i] != three[i]) num++;
                if (num > 1) break;
            }
            if (num == 1) {
                cout << ten << '\n';
                return 0;
            }
        }
        if (two[i] == '0') two[i] = '1';
        else two[i] = '0';
    }
    return 0;
}