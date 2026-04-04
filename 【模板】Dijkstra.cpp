#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int maxn=1e5+5;
int n,m,s;
struct edge{
    int to,w;
};
vector<edge> to[maxn];
int dis[maxn];
priority_queue<P,vector<P>,greater<P> > pq;
void Dijkstra(int st){
    memset(dis,0x3f,sizeof dis); dis[st]=0;
    pq.push({0,st});
    while(!pq.empty()){
        int uw=pq.top().first,uid=pq.top().second;
        pq.pop();
        if(uw>dis[uid]) continue;
        for(const auto &v:to[uid]){
            if(dis[v.to]>uw+v.w){
                dis[v.to]=uw+v.w;
                pq.push({dis[v.to],v.to});
            }
        }
    }
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        to[u].push_back({v,w});
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<' ';
    }
    return 0;
}