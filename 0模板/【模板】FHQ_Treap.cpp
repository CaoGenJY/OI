#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=1e8;
struct FHQ_Treap{
    int rt,idx;
    struct node{
        int l,r;
        int siz,val,key;
    }tr[maxn];
    int newnode(int k){
        tr[++idx].key=k; tr[idx].val=rand();
        tr[idx].siz=1; tr[idx].l=tr[idx].r=0;
        return idx;
    }
    void pushup(int p){
        tr[p].siz=tr[tr[p].l].siz+tr[tr[p].r].siz+1;
    }
    void split(int p,int k,int &x,int &y){
        if(!p) x=y=0;
        else{
            if(tr[p].key<=k){
                x=p;
                split(tr[p].r,k,tr[p].r,y);
            }else{
                y=p;
                split(tr[p].l,k,x,tr[p].l);
            }
            pushup(p);
        }
    }
    int merge(int x,int y){
        if(!x||!y) return x+y;
        if(tr[x].val>tr[y].val){
            tr[x].r=merge(tr[x].r,y);
            pushup(x);
            return x;
        }else{
            tr[y].l=merge(x,tr[y].l);
            pushup(y);
            return y;
        }
    }
    int x,y,z;
    void insert(int k){
        split(rt,k,x,y);
        rt=merge(merge(x,newnode(k)),y);
    }
    void del(int k){
        split(rt,k,x,z); split(x,k-1,x,y);
        y=merge(tr[y].l,tr[y].r);
        rt=merge(merge(x,y),z);
    }
    int get_rank(int k){
        split(rt,k-1,x,y);
        int ret=tr[x].siz;
        merge(x,y);
        return ret+1;
    }
    int get_key(int rank){
        int now=rt;
        while(now){
            if(tr[tr[now].l].siz+1==rank){
                break;
            }else if(tr[tr[now].l].siz>=rank){
                now=tr[now].l;
            }else{
                rank-=tr[tr[now].l].siz+1;
                now=tr[now].r;
            }
        }
        return tr[now].key;
    }
    int get_prev(int k){
        split(rt,k-1,x,y);
        int now=x;
        while(tr[now].r){
            now=tr[now].r;
        }
        int ret=tr[now].key;
        rt=merge(x,y);
        return ret;
    }
    int get_next(int k){
        split(rt,k,x,y);
        int now=y;
        while(tr[now].l){
            now=tr[now].l;
        }
        int ret=tr[now].key;
        merge(x,y);
        return ret;
    }
}bt;
int n,opt,x;
int main(){
    srand(114514);
    cin.tie(0)->ios::sync_with_stdio(false); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>opt>>x;
        if(opt==1){
            bt.insert(x);
        }else if(opt==2){
            bt.del(x);
        }else if(opt==3){
            cout<<bt.get_rank(x)<<'\n';
        }else if(opt==4){
            cout<<bt.get_key(x)<<'\n';
        }else if(opt==5){
            cout<<bt.get_prev(x)<<'\n';
        }else{
            cout<<bt.get_next(x)<<'\n';
        }
    }
    return 0;
}