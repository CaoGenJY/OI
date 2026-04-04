#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+4;
int n,m;
int k[maxn],dfan[maxn];
bool vis[maxn];
vector<int> fan[maxn],kk[maxn];
queue<int> q;
void topsort1(){
    for(int i=1;i<=n;i++){
        if(!dfan[i]) q.push(i); 
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(const auto &v:fan[u]){
            dfan[v]--;
            k[v]=min(k[v],k[u]-1);
            if(!dfan[v]){
                q.push(v);
            }
        }
        kk[k[u]].push_back(u);
    }
}
void dfs(int u){
    vis[u]=1;
    for(const auto &v:fan[u]){
        if(!vis[v]) dfs(v);
    }
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        dfan[u]++;
        fan[v].push_back(u);
    }
    topsort1();
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        dfs(i);
        int p=n;
        for(int j=n;j>=1;j--){
            if(p>j) break;
            for(const auto u:kk[j]){
                if(!vis[u]) p--;
            }
        }
        cout<<p<<' ';
    }
    cout<<'\n';
    return 0;
}