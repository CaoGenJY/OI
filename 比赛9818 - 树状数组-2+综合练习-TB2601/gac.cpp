#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e3+3;
ll primes[maxn],f[maxn];
bool vis[maxn];
void sieve(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            primes[++primes[0]]=i;
        }
        for(int j=1;j<=primes[0]&&i*primes[j]<=n;j++){
            vis[i*primes[j]]=true;
            if(i%primes[j]==0) break;
        }
    }
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    ll n; cin>>n;
    sieve(n);
    f[0]=1;
    for(int i=1;i<=primes[0]&&primes[i]<=n;i++){
        for(int j=n;j>=1;j--){
            for(int k=primes[i];k<=j;k*=primes[i]){
                f[j]+=f[j-k];
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=n;i++) ans+=f[i];
    cout<<ans;
    return 0;
}