#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m1,m2,idx1;
struct bcj{
    int fa[maxn];
    void init(){
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    int find(int x){
        if(x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
    void unity(int x,int y){
        x=find(x); y=find(y);
        fa[x]=y;
    }
}b1,b2;
map<pair<int,int>,int> mp;
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
    cin>>n>>m1>>m2; b1.init(); b2.init();
    for(int i=1;i<=m1;i++){
        int u,v; cin>>u>>v;
        b1.unity(u,v);
    }
    for(int i=1;i<=m2;i++){
        int u,v; cin>>u>>v;
        b2.unity(u,v);
    }
    for(int i=1;i<=n;i++){
        mp[{b1.find(i),b2.find(i)}]++;
    }
    for(int i=1;i<=n;i++){
        cout<<mp[{b1.find(i),b2.find(i)}]<<' ';
    }
    return 0;
}