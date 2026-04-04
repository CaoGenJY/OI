#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2005;
ll n,k;
ll a[maxn],f[maxn];
int minn[maxn][maxn];
int main(){
    freopen("c.in","r",stdin);freopen("c.out","w",stdout);
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>k;
    ll ans=LLONG_MAX;
    for(int i=0;i<n;i++){
        cin>>a[i];
        f[i]=a[i];
    }
    for(int t=0;t<n;t++){
        ll cur=t*k;
        for(int i=0;i<n;i++){
            f[i]=min(f[i],a[(i-t+n)%n]);
            cur+=f[i];
        }
        ans=min(ans,cur);
    }
    cout<<ans;
    return 0;
}