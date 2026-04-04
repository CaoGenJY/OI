#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll n,ans=1;
ll qsm(ll a,ll k){
    ll ret=1;
    while(k){
        if(k&1) (ret*=a)%=mod;
        (a*=a)%=mod;
        k>>=1;
    }
    return ret;
}
int main(){
    freopen("crotate.in","r",stdin);
    freopen("crotate.out","w",stdout);
    cin>>n;
    if(n%2==1) ans*=3;
    n/=2;
    if(!n){
        cout<<ans<<'\n';
        return 0;
    }
    n--; ans*=4;
    (ans*=qsm(5,n))%=mod;
    cout<<ans<<'\n';
    return 0;
}