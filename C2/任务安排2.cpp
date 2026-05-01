#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=3e5+5;
int n,s;
ll c[maxn],t[maxn],f[maxn],q[maxn];
int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&t[i],&c[i]);
        t[i]+=t[i-1];
        c[i]+=c[i-1];
    }
    int hh=0,tt=0;
    for(int i=1;i<=n;i++){
        while(hh<tt&&(f[q[hh+1]]-f[q[hh]])<=(t[i]+s)*(c[q[hh+1]]-c[q[hh]])) hh++;
        int j=q[hh];
        f[i]=f[j]-(t[i]+s)*c[j]+t[i]*c[i]+s*c[n];
        while(hh<tt&&(f[q[tt]]-f[q[tt-1]])*(c[i]-c[q[tt]])>=(c[q[tt]]-c[q[tt-1]])*(f[i]-f[q[tt]])) tt--;
        q[++tt]=i;
    }
    printf("%lld\n",f[n]);
    return 0;
}