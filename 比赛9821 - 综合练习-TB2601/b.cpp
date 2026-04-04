#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll n,k,pos,zcnt,fcnt;
ll a[maxn],z[maxn],f[maxn];
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>k;
    a[0]=-1;
    pos=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=0&&a[i-1]<0) pos=i;
    }
    if(pos==-1) pos=n+1;
    for(int i=pos-1;i>=1;i--) f[++fcnt]=-a[i];
    for(int i=pos;i<=n;i++) z[++zcnt]=a[i];
    ll ans=LLONG_MAX;
    if(zcnt>=k) ans=min(ans,z[k]);
    if(fcnt>=k) ans=min(ans,f[k]);
    for(int i=0;i<=min(zcnt,k);i++){
        if(k-i>fcnt) continue;
        ans=min(ans,z[i]*2+f[k-i]);
    }
    for(int i=0;i<=min(fcnt,k);i++){
        if(k-i>zcnt) continue;
        ans=min(ans,f[i]*2+z[k-i]);
    }
    cout<<ans<<'\n';
    return 0;
}