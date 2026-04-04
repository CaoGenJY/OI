#include<bits/stdc++.h>
using namespace std;
uint32_t x = 0, y = 1, z = 2, w = 3;
uint32_t generate() { 
    uint32_t t = (x^(x<<11));
    x = y;
    y = z;
    z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
    return w;
}
uint32_t a[10000001];

int main() {
    freopen("memory.in","r",stdin);
    freopen("memory.out","w",stdout);
    int64_t seed; cin >> seed; 
    x = seed;
    for (int i = 0; i < 10000001; i++) {
        a[i] = generate();
    }
    sort(a,a+10000000);
    cout<<a[10000000/2];
    return 0;
}