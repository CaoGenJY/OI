#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int rt,tot;
int fa[maxn],ch[maxn][2],val[maxn],cnt[maxn],sz[maxn];
inline bool get(int x) {return ch[fa[x]][1]==x;}  //x是左子节点--0,右子节点--1
inline void pushup(int x){
    if(x){
        sz[x]=cnt[x];
        if(ch[x][0]) sz[x]+=sz[ch[x][0]];
        if(ch[x][1]) sz[x]+=sz[ch[x][1]];
    }
}
void rotate(int x){  //右旋拎左右挂左，左旋拎右左挂右
    int y=fa[x],z=fa[y],k=get(x);   //k==0->右旋
    ch[y][k]=ch[x][k^1]; fa[ch[x][k^1]]=y;
    ch[x][k^1]=y,fa[y]=x;
    if(z) ch[z][ch[z][1]==y]=x;
    pushup(y); pushup(x);  //注意先pushup深的再pushup浅的
}
void splay(int x){
    while(fa[x]!=0){
        int y=fa[x],z=fa[y];
        //zig-zag/zag-zig先转x再转x,zig-zig/zag-zag先转y再转x
        if(z!=0){
            rotate(get(x)==get(y)?y:x);  
        }
        rotate(x);
    }
}
void find(int x){
    int u=rt;
    if(!u) return;
    while(x!=val[u]&&ch[u][x>val[u]]){
        u=ch[u][x>val[u]];
    }
    splay(u);
}
void insert(int x){
    int u=rt,f=0;
    while(u&&val[u]!=x){
        f=u;
        u=ch[u][x>val[u]];
    }
    if(u) cnt[u]++,pushup(u),pushup(f);
    else{
        u=++tot;
        val[u]=x; sz[u]=cnt[u]=1;
        fa[u]=f; ch[u][0]=ch[u][1]=0;
        if(f) ch[f][u>val[f]]=u,pushup(f);
        else rt=u;
    }
    splay(u);
}
int qrank(int x){
    find(x);
    return sz[ch[rt][0]]+1;
}
int qkth(int x){
    
}
int main(){
     
}