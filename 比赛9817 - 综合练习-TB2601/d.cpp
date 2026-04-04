#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n;
ll a[maxn];
ll ans(ll x){
    long long ret=0;
    for(int i=1;i<=n;i++) ret+=llabs(a[i]-x);
    return ret;
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long v;
        cin>>v;
        a[i]=v - i;
    }
    sort(a+1,a+n+1);
    if(n%2==1) cout<<ans(a[n/2+1]);
    else cout<<min(ans(a[n/2]), ans(a[n/2+1]));
    return 0;
}