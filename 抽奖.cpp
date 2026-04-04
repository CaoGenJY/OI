#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const int maxn=25;
ll n,f[maxn],fac;
int main(){
    cin>>n;
    f[1]=0,f[2]=1;
    fac=2;
    for(int i=3;i<=n;i++){
        fac*=i;
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    }
    cout<<fixed<<setprecision(2)<<f[n]*100.0/fac<<'%';
    return 0;
}
/*
1 2 3
2 3 1
3 1 2
*/