#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
struct node{
    int x,y,h;
}a[maxn];
struct Edge{
    int to,w;
};
int n,m,x,y,t;
bool jh[maxn];
vector<Edge> to[maxn];
int find(int x){
    for(int i=1;i<=n;i++){
        if(a[i].x==x) return i;
    }
    return 0;
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].h;
        a[i].h+=a[i].y;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        w=find(u+w);
        u=find(u-1);
        to[u].push_back({w,v});
        to[w].push_back({u,v});
    }
    cin>>x>>y;
    jh[1]=true;
    while(true){
        bool flg=true;
        while(flg){
            flg=false;
            for(int u=1;u<=n;u++){
                if(!jh[u]) continue;
                for(const auto &v:to[u]){
                    if(a[u].h<=v.w&&!jh[v.to]) jh[v.to]=1;
                }
            }
            int maxx=0;
            for(int i=1;i<=n;i++){
                if(jh[i]) maxx=max(maxx,a[i].h);
                if(jh[x]&&maxx==y){
                    cout<<t<<'\n';
                    return 0;
                }
            }
            for(int i=1;i<=n;i++){
                if(jh[i]&&a[i].y==a[i].h&&a[i].y==maxx){
                    cout<<-1;
                    return 0;
                }
            }
            for(int i=1;i<=n;i++){
                if(jh[i]&&a[i].h==maxx){
                    a[i].h--;
                    t++;
                }
            }
        }
    }
    return 0;
}