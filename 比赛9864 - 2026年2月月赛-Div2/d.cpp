#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,m,cnt;
bool vis[maxn],is_zhan[maxn];
int d[maxn];
vector<int> to[maxn],zhan;
void dfs(int u){
    for(const auto &v:to[u]){
        if(!vis[v]){
            vis[v]=1;
            dfs(v);
        }
    }
}
void init(){
    memset(vis,false,sizeof vis);
    memset(is_zhan,false,sizeof is_zhan);
    memset(d,0,sizeof d);
    for(int i=1;i<=n;i++){
        to[i].clear();
    }
    zhan.clear();
}
void solve(){
    cin>>n>>m;
    init();
    int cs=-1;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
        d[u]++; d[v]++;
        is_zhan[u]=is_zhan[v]=true;
        if(cs==-1) cs=u;
    }
    vis[cs]=true;
    dfs(cs);
    for(int i=0;i<n;i++){
        if(!is_zhan[i]) continue;
        cnt+=d[i]%2;
        if(!vis[i]){
            cout<<"NO\n";
            return;
        }
    }
    if(!cnt||cnt==2){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return;
}
int main(){
    freopen("train.in","r",stdin);
    freopen("train.out","w",stdout);
    int T; cin>>T; while(T--) solve();
    return 0;
}