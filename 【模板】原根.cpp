#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#define ll long long
using namespace std;
const int maxn=1e6+6;
int primes[maxn],vis[maxn],phi[maxn],yz[maxn],ans[maxn];
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
ll qsm(ll a,ll k,ll p){
    ll ret=1;
    while(k){
        if(k&1) (ret*=a)%=p;
        (a*=a)%=p;
        k>>=1;
    }
    return ret;
}
void euler(int n){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            primes[++primes[0]]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=primes[0]&&i*primes[j]<n;j++){
            int p=primes[j];
            vis[i*p]=1;
            if(i%p==0){
                phi[i*p]=phi[i]*p;
            }else{
                phi[i*p]=phi[i]*(p-1);
            }
        }
    }
}
void get_yz(ll n){
    yz[0]=0;
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            yz[++yz[0]]=i;
            while(n%i==0) n/=i;
        }
    }
    if(n>1) yz[++yz[0]]=n;
}
void solve(){
    int n,d; cin>>n>>d;
    get_yz(phi[n]);
    int g0=2;
    for(;g0<=n;g0++){
        bool flg=true;
        for(int j=1;j<=yz[0];j++){
            if(qsm(g0,phi[n]/yz[j],n)==1){
                flg=false;
                break;
            }
        }
        if(flg) break;
    }
    cout<<phi[phi[n]]<<'\n';
    ans[0]=0;
    for(int i=1;i<=phi[n];i++){
        if(gcd(i,phi[n])==1) ans[++ans[0]]=qsm(g0,i,n);
    }
    sort(ans+1,ans+ans[0]+1);
    for(int i=1;i<=phi[phi[n]]/d;i++) cout<<ans[i]<<' ';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    int T; cin>>T;
    euler(maxn);
    while(T--){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000.0<<"ms\n";
    #endif
    return 0;
}