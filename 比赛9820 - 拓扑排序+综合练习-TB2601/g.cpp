#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,m,st,ed,fa[maxn];
struct Edge{
    int u,v,w;
}e[maxn];
void init(){
    for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void unity(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y) fa[x]=y;
}
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    cin>>st>>ed;
    sort(e+1,e+m+1,cmp);
    int a=-1,b=1;
    for(int i=1;i<=m;i++){
        init();
        for(int j=i;j<=m;j++){
            unity(e[j].u,e[j].v);
            if(find(st)==find(ed)){
                if(a==-1||e[j].w*b<a*e[i].w){
                    a=e[j].w;
                    b=e[i].w;
                }
                break;
            }
        }
    }
    if(a==-1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int d=__gcd(a,b);
    a/=d;b/=d;
    if(b==1) cout<<a;
    else cout<<a<<'/'<<b;
    return 0;
}
