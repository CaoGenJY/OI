#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    int n, m;
    n = 5;
    m = rand()%n+1;
    cout << n << " " << m << "\n";
    for(int i = 1; i <= n; i++){
        cout << rand()%10+1 << " ";
    }
    cout << "\n";
    return 0;
}