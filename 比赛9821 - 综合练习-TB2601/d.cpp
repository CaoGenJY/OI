#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll n,m,ans,cnt;
ll a[maxn];
map<ll,ll> mp;
int main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m; mp[0]++;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
        ans+=mp[a[i]%m];
        mp[a[i]%m]++;
    }
    cout<<ans;
    return 0;
}