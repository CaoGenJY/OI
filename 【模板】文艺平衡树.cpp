#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=1e8;
struct FHQ_Treap{
    int idx=0,rt;
    struct node{
        int l,r;
        int val,key,siz;
        bool lzy;
    }tr[maxn];
    int newnode(int k){
        tr[++idx].key=k; tr[idx].val=rand();
        tr[idx].siz=1; tr[idx].lzy=false;
        return idx;
    }
    void pushup(int p){
        tr[p].siz=tr[tr[p].l].siz+tr[tr[p].r].siz+1;
    }
    void pushdown(int p){
        if(!tr[p].lzy) return;
        swap(tr[p].l,tr[p].r);
        tr[tr[p].l].lzy^=1;
        tr[tr[p].r].lzy^=1;
        tr[p].lzy=0;
    }
    void split(int p,int siz,int &x,int &y){
        if(!p){
            x=y=0;
            return;
        }
        pushdown(p);
        if(tr[tr[p].l].siz>=siz){
            y=p;
            split(tr[p].l,siz,x,tr[p].l);
        }else{
            siz-=tr[tr[p].l].siz+1;
            x=p;
            split(tr[p].r,siz,tr[p].r,y);
        }
        pushup(p);
    }
    int merge(int x,int y){
        if(!x||!y) return x+y;
        else if(tr[x].val>tr[y].val){
            pushdown(x);
            tr[x].r=merge(tr[x].r,y);
            pushup(x);
            return x;
        }else{
            pushdown(y);
            tr[y].l=merge(x,tr[y].l);
            pushup(y);
            return y;
        }
    }
    int x,y,z;
    void reverse(int l,int r){
        split(rt,l-1,x,z);
        split(z,r-l+1,y,z);
        tr[y].lzy^=1;
        rt=merge(x,merge(y,z));
    }
    void build(int n){
        for(int i=1;i<=n;i++){
            rt=merge(rt,newnode(i));
        }
    }
    void output(int p){
        if(p==0) return;
        pushdown(p);
        output(tr[p].l);
        cout<<tr[p].key<<' ';
        output(tr[p].r);
    }
}bt;
int n,m;
int main(){
    srand(114514);
    cin.tie(0)->ios::sync_with_stdio(false); cout.tie(0);
    cin>>n>>m;
    bt.build(n);
    for(int i=1;i<=m;i++){
        int l,r; cin>>l>>r;
        bt.reverse(l,r);
    }
    bt.output(bt.rt);
    return 0;
}