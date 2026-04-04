#include<bits/stdc++.h>
using namespace std;
const int maxn=305,maxm=1e4+4;
int n,m,l=0,r=0,ans=0;
struct Edge{
    int u,v,w;
}e[maxm];
int fa[maxm];
void init() {for(int i=1;i<=m;i++) fa[i]=i;}
int find(int x) {if(x==fa[x]) return x; return fa[x]=find(fa[x]);}
void unity(int u,int v) {u=find(u); v=find(v); fa[u]=v;}
bool cmp(Edge x,Edge y) {return x.w<y.w;}
bool check(int x){
    int cnt=0;
    init();
    for(int i=1;i<=m;i++){
        if(e[i].w>x) break;
        if(find(e[i].u)!=find(e[i].v)){
            unity(e[i].u,e[i].v);
            cnt++;
        }
        if(cnt==n-1) return true;
    }
    return false;
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
        r=max(r,e[i].w);
    }
    sort(e+1,e+m+1,cmp);
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<n-1<<' '<<ans;
    return 0;
}