#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2005,mod=1e9+7;
vector<ll> invfac;
vector<ll> fac;
ll qmi(ll a, ll k, ll p) {
    ll res = 1 % p;
    while(k) {
        if(k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
void init(int n) {
    fac.resize(n + 1); invfac.resize(n + 1);
    fac[0] = 1;
    for(int i = 1; i <= n; i ++ ) {
        fac[i] = (unsigned int)(1ll * i * fac[i - 1] % mod);
    }
    invfac[n] = qmi(fac[n], mod - 2, mod);
    for(int i = n - 1; i >= 0; i -- ){
        invfac[i] = invfac[i + 1] % mod * (i + 1) % mod;
    }
}
ll C(int a,int b){
    return fac[a] % mod * invfac[b] % mod * invfac[a - b] % mod;
}
int n,m,a[maxn];
ll ans;
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m;
    init(maxn);
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        ll tmp=C(n,i);
        for(int j=1;j<=m;j++){
            tmp*=C(a[j]+n-i-1,n-i-1);
            tmp%=mod;
        }
        if(i&1) ans=(ans-tmp+mod)%mod;
        else ans=(ans+tmp+mod)%mod;
    }
    cout<<ans;
    return 0;
}