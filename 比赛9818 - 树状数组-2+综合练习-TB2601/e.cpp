#include<bits/stdc++.h>
#define ll long long
#define P pair<int,int>
using namespace std;
ll readu(){ll k=0,f=1; char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9') k=k*10+ch-'0',ch=getchar();return k*f;}
void write(ll x){if(x<0)putchar('-'),x=-x;if(x<10)putchar(x+'0');else write(x/10),putchar(x%10+'0');}
const int maxn=505;
const int INF=0x3f3f3f3f;
int t,n,m,k,d;
struct Ban{
    int id,l,r;
}b[maxn];
struct edge{
    int to,w;
};
vector<edge> to[maxn];
int ban[maxn];
ll c[maxn][maxn],f[maxn],ans[maxn],dis[maxn];
priority_queue<P,vector<P>,greater<P> > pq;
int Dijkstra(int l,int r){
    memset(ban,false,sizeof ban);
    for(int i=1;i<=d;i++){
        if(r>=b[i].l&&l<=b[i].r){
            ban[b[i].id]=true;
        }
    }
    if(ban[1]||ban[n]) return INF;
    memset(dis,0x7f,sizeof dis); dis[1]=0;
    while(!pq.empty()) pq.pop();
    pq.push({0,1});
    while(!pq.empty()){
        int uw=pq.top().first,uid=pq.top().second;
        pq.pop();
        if(ban[uid]||uw>dis[uid]) continue;
        for(const auto &v:to[uid]){
            if(ban[v.to]) continue;
            if(dis[v.to]>uw+v.w){
                dis[v.to]=uw+v.w;
                pq.push({dis[v.to],v.to});
            }
        }
    }
    if(dis[n]>=INF) return INF;
    return dis[n];
}

int main(){
    t=readu(); n=readu(); k=readu(); m=readu();
    for(int i=1;i<=m;i++){
        int u,v,w; u=readu(); v=readu(); w=readu();
        to[u].push_back({v,w});
        to[v].push_back({u,w});
    }
    d=readu();
    for(int i=1;i<=d;i++){
        b[i].id=readu(); b[i].l=readu(); b[i].r=readu();
    }
    for(int i=1;i<=t;i++){
        for(int j=i;j<=t;j++){
            c[i][j]=Dijkstra(i,j);
        }
    }
    memset(f,0x7f,sizeof f);
    for(int i=1;i<=t;i++){
        if(c[1][i]>=INF) f[i]=LLONG_MAX;
        else f[i]=c[1][i]*i;
        for(int j=1;j<i;j++){
            if(f[j]==LLONG_MAX||c[j+1][i]>=INF) continue;
            f[i]=min(f[i],f[j]+c[j+1][i]*(i-j)+k);
        }
    }
    write(f[t]);
    return 0;
}
