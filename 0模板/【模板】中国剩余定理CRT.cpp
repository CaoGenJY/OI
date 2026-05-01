#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll n,pm=1;
ll a[maxn],m[maxn];
__int128 ans=0;
inline void write(__int128 a)
{
    if(a>9) write(a/10);
    putchar((a%10)|48);
}
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll t=y;
    y=x-a/b*y;
    x=t;
    return;
}
ll inv(ll x,ll m){  //求x在mod m下的逆元
    ll a=0,b=0;
    exgcd(x,m,a,b);
    return (a%m+m)%m;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>a[i];
        pm*=m[i];
    }
    for(int i=1;i<=n;i++){
        ll mm=pm/m[i];
        ans+=(__int128)a[i]*mm*inv(mm,m[i]); ans%=pm;
    }
    write(ans);
    return 0;
}