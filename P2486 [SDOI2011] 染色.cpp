#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
int w[maxn],anc[maxn][20],d[maxn];
vector<int> to[maxn];
void dfs(int u,int f){
    for(const auto &v:to[u]){
        if(v==f) continue;
        d[v]=d[u]+1;
        anc[v][0]=u;
        dfs(v,u);
    }
}
void init(){
    dfs(1,0);
    for(int j=1;j<=18;j++){
        for(int i=1;i<=n;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
}
int lca(int u,int v){
    if(d[u]<d[v]) swap(u,v);
    for(int i=18;i>=0;i--){
        if(d[anc[u][i]]>=d[v]) u=anc[u][i];
    }
    if(u==v) return u;
    for(int i=18;i>=0;i--){
        if(anc[u][i]!=anc[v][i]) u=anc[u][i],v=anc[v][i];
    }
    return anc[u][0];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    init();
    while(m--){
        char op;
        int x,y,z;
        cin>>op>>x>>y;
        int L=lca(x,y);
        if(op=='C'){
            cin>>z;
            w[L]=z;
            while(x!=L){
                w[x]=z;
                x=anc[x][0];
            }
            while(y!=L){
                w[y]=z;
                y=anc[y][0];
            }
        }else{
            int ans=1,now=w[x];
            while(x!=L){
                x=anc[x][0];
                if(now!=w[x]) ans++;
                now=w[x];
            }
            now=w[y]; ans++;
            while(y!=L){
                y=anc[y][0];
                if(now!=w[y]) ans++;
                now=w[y];
            }
            cout<<max(ans-1,1)<<'\n';
        }
    }
}