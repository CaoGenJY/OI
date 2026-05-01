#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+3;
const ll p=998244353;
ll ksm(ll a,ll k){
	ll ret=1;
	while(k){
		if(k&1) ret=ret*a%p;
		a=a*a%p;
		k>>=1;
	}
	return ret;
}
ll n,k;
ll x[maxn],y[maxn];
void solve(){
    cin>>n>>k;
    for(int i=0;i<=n;i++){
    	cin>>x[i]>>y[i];
    }
    ll ans=0;
    for(int i=0;i<=n;i++){
    	ll det=y[i];
    	for(int j=0;j<=n;j++){
    		if(i==j) continue;
    		det=det
    		*((k-x[j]+p)%p)
    		*(ksm((x[i]-x[j]+p)%p,p-2)%p)%p;
    	}
    	ans=(ans+det)%p;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("in.in","r",stdin);
    // freopen("out.out","w",stdout);
    // #endif
    int T=1; //cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000.0<<"ms\n";
    #endif
    return 0;
}