#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> to[maxn];
int n,rt,Q,mod;
int son[maxn],id[maxn],w[maxn],wt[maxn],fa[maxn],cnt,dep[maxn],siz[maxn],top[maxn];
//分别为:重儿子编号,新序号,初始权值,新权值,父节点,dfs序,深度,子树大小,所在重链的顶端
struct SegmentTree{
    int tr[maxn<<2],lzy[maxn<<2];
    bool inrange(int l,int r,int L,int R){return L<=l&&r<=R;}
    bool outrange(int l,int r,int L,int R){return r<L||R<l;}
    void pushup(int u){tr[u]=(tr[u<<1]+tr[u<<1|1])%mod;}
    void maketag(int u,int l,int r,int v){
        tr[u]=(tr[u]+1ll*(r-l+1)*v)%mod;
        lzy[u]=(lzy[u]+v)%mod;
    }
    void pushdown(int u,int l,int r){
        if(lzy[u]){
            int mid=(l+r)>>1;
            maketag(u<<1,l,mid,lzy[u]);
            maketag(u<<1|1,mid+1,r,lzy[u]);
            lzy[u]=0;
        }
    }
    void build(int* a,int u,int l,int r){
        if(l==r){tr[u]=a[l]%mod;return;}
        int mid=(l+r)>>1;
        build(a,u<<1,l,mid);
        build(a,u<<1|1,mid+1,r);
        pushup(u);
    }
    void modify(int u,int l,int r,int L,int R,int v){
        if(inrange(l,r,L,R)){maketag(u,l,r,v);return;}
        if(outrange(l,r,L,R)) return;
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        modify(u<<1,l,mid,L,R,v);
        modify(u<<1|1,mid+1,r,L,R,v);
        pushup(u);
    }
    int query(int u,int l,int r,int L,int R){
        if(inrange(l,r,L,R)) return tr[u];
        if(outrange(l,r,L,R)) return 0;
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        return (query(u<<1,l,mid,L,R)+query(u<<1|1,mid+1,r,L,R))%mod;
    }
}segtree;
inline void dfs1(int x,int f,int deep){
    dep[x]=deep;
    fa[x]=f;
    siz[x]=1;
    int maxson=-1; //记录重儿子的儿子数
    for(const auto &y:to[x]){
        if(y==f) continue;
        dfs1(y,x,deep+1);
        siz[x]+=siz[y];
        if(siz[y]>maxson) son[x]=y,maxson=siz[y];
    }
}
inline void dfs2(int x,int topf){ //topf为当前链最顶端的节点
    id[x]=++cnt;
    wt[cnt]=w[x];
    top[x]=topf;
    if(!son[x]) return;
    dfs2(son[x],topf);
    for(const auto &y:to[x]){
        if(y==fa[x]||y==son[x]) continue;
        dfs2(y,y);
    }
}
int qRange(int x,int y){
    int ret=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        (ret+=segtree.query(1,1,n,id[top[x]],id[x]))%=mod;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    (ret+=segtree.query(1,1,n,id[x],id[y]))%=mod;
    return ret;
}
inline void updRange(int x,int y,int v){
    v%=mod;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        segtree.modify(1,1,n,id[top[x]],id[x],v);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    segtree.modify(1,1,n,id[x],id[y],v);
}
int qSon(int x){
    return segtree.query(1,1,n,id[x],id[x]+siz[x]-1);
}
inline void updSon(int x,int v){
    segtree.modify(1,1,n,id[x],id[x]+siz[x]-1,v);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>Q>>rt>>mod;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        to[u].push_back(v); to[v].push_back(u);
    }
    dfs1(rt,0,1);
    dfs2(rt,rt);
    segtree.build(wt,1,1,n);
    while(Q--){
        int op,x,y,z;
        cin>>op;
        if(op==1){
            cin>>x>>y>>z;
            updRange(x,y,z);
        }else if(op==2){
            cin>>x>>y;
            cout<<qRange(x,y)<<'\n';
        }else if(op==3){
            cin>>x>>y;
            updSon(x,y);
        }else if(op==4){
            cin>>x;
            cout<<qSon(x)<<'\n';
        }
    }
}