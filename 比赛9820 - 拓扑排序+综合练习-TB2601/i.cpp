#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e4+4,mod=10007;
int n,m;
ll a[maxn],sum1[maxn],sum2[maxn],rem[maxn],f[maxn];
ll ans,anss;
bool chk(int x){
    ll now=0,ret=1;
    for(int i=1;i<=n;i++){
        now+=a[i];
        if(a[i]>x) return 0;
        if(now>x){
            ret++;
            now=a[i];
        }
    }
    return ret<=m+1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum1[i]=sum1[i-1]+a[i];
    }
    int l=1,r=1e8;
    while(l<=r){
        int mid=(l+r)>>1;
        if(chk(mid)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    int j=0;
    for(int i=1;i<=n;i++){
        for(;j<i;j++){
            if(sum1[i]-sum1[j]<=ans){
                rem[i]=j;
                break;
            }
        }
    }
    int res=0; if(sum1[n]<=ans) anss=1;
    for(int i=1;i<=n;i++){
        if(sum1[i]<=ans) f[i]=1;
        sum2[i]=(sum2[i-1]+f[i])%mod;
    }
    for(int i=2;i<=m+1;i++){
        for(int j=1;j<=n;j++){
            f[j]=sum2[j-1];
            if(rem[j]>=1){
                ((f[j]-=sum2[rem[j]-1])+=mod)%=mod;
            }
        }
        for(int j=1;j<=n;j++) sum2[j]=(sum2[j-1]+f[j])%mod;
        (anss+=f[n])%=mod;
    }
    cout<<ans<<' '<<anss;
    return 0;
}