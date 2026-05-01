#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+4,inf=0x3f3f3f3f;
struct edge{
	int to,nxt;
	ll w;
}e[maxn]; int idx=1;
int head[maxn];
void add(int u,int v,int w){
	e[++idx].to=v; e[idx].w=w; e[idx].nxt=head[u]; head[u]=idx;
	e[++idx].to=u; e[idx].w=0; e[idx].nxt=head[v]; head[v]=idx;
}
int n,m,s,t;
ll ans=0;
ll dis[maxn],now[maxn];
queue<int> q;
bool bfs(){
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++){
		now[i]=head[i];
		dis[i]=-1;
	}
	q.push(s); dis[s]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!e[i].w||dis[v]!=-1) continue;
			q.push(v);
			dis[v]=dis[u]+1;
			if(v==t) return true;
		}
	}
	return false;
}
ll dinic(int u,ll flow){
	if(u==t) return flow;
	int rest=flow;
	for(int i=now[u];i&&rest;i=e[i].nxt){
		now[u]=i; int v=e[i].to;
		if(e[i].w&&dis[v]==dis[u]+1){
			int k=dinic(v,min<ll>(rest,e[i].w));
			if(k==0) dis[v]=-1;
			e[i].w-=k;
			e[i^1].w+=k;
			rest-=k;
		}
	}
	return flow-rest;
}
void solve(){
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
    	int u,v,w; cin>>u>>v>>w;
    	add(u,v,w);
    }
    while(bfs()){
    	ans+=dinic(s,inf);
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    int T=1; //cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000.0<<"ms\n";
    #endif
    return 0;
}
