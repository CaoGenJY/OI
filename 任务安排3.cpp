#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=3e5+5;
int n,s,hh=0,tt=0;
ll c[maxn],t[maxn],f[maxn],q[maxn];
int bsearch(int x){  //x --> current slope
    int l=hh,r=tt;
    while(l<r){
        int mid=l+r>>1;
        if((f[q[mid+1]]-f[q[mid]])>x*(c[q[mid+1]]-c[q[mid]])) r=mid;
        else l=mid+1;
    }
    return r;
}
int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&t[i],&c[i]);
        t[i]+=t[i-1];
        c[i]+=c[i-1];
    }
    for(int i=1;i<=n;i++){
        int j=q[bsearch(t[i]+s)];
        f[i]=f[j]-(t[i]+s)*c[j]+t[i]*c[i]+s*c[n];
        while(hh<tt&&(f[q[tt]]-f[q[tt-1]])*(c[i]-c[q[tt]])>=(c[q[tt]]-c[q[tt-1]])*(f[i]-f[q[tt]])) tt--;
        q[++tt]=i;
    }
    printf("%lld\n",f[n]);
    return 0;
}