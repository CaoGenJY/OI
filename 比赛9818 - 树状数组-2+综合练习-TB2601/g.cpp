#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}
ll ans=0;
map<ll,ll> mp;
void dfs(ll n,ll now,ll l){
    if(n==0){
        if(!mp.count(l)){
            mp[l]=1;
            ans++;
        }
        return;
    }
    for(int i=now;i<=n;i++){
        dfs(n-i,i,lcm(l,i));
    }
}
signed main(){
    ll n; cin>>n;
    dfs(n,1,1);
    cout<<ans;
    return 0;
}