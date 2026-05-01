#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int m,n,idx;
int fa[maxn*maxn<<1],a[maxn],b[maxn];
struct Edge{
    int u,v,w;
    bool operator <(Edge &b){
        return w<b.w;
    }
}e[maxn*maxn<<1];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unity(int x,int y){
    fa[find(x)]=find(y);
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>a[1]>>b[1]>>n>>m;
    n++;m++;
    for(int i=2;i<=n;i++) cin>>a[i];
    for(int i=2;i<=m;i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            fa[i*(m+1)+j]=i*(m+1)+j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            e[++idx].u=(i-1)*m+j-1;
            e[idx].v=(i-1)*m+j;
            e[idx].w=a[i]-a[i-1];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            e[++idx].u=(i-1)*m+j-1;
            e[idx].v=i*m+j-1;
            e[idx].w=b[j]-b[j-1];
        }
    }
    sort(e+1,e+idx+1);
    unsigned long long cnt=0,ans=0;
    for(int i=1;i<=idx;i++){
        if(find(e[i].u)!=find(e[i].v)){
            unity(e[i].u,e[i].v);
            ans+=e[i].w;
            cnt++;
        }
    }
    cout<<ans;
    return 0;
}