#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+4;
int n,m;
int fa[maxn],siz[maxn];
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        siz[i]=1;
    }
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void unity(int x,int y){    //x->y
    x=find(x); y=find(y);
    fa[x]=y;
    siz[y]+=siz[x];
}
int main(){
    freopen("monkey.in","r",stdin);
    freopen("monkey.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        x=find(x); y=find(y);
        if(x==y) continue;
        if(siz[x]==siz[y]){
            if(x<y) unity(y,x);
            else unity(x,y);
        }else{
            if(siz[x]>siz[y]) unity(y,x);
            else unity(x,y);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<find(i)<<'\n';
    }
    return 0;
}