#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=1e8;
struct Treap{
    int idx=0,rt=0;
    struct node{
        int l,r;
        int key,val;
        int cnt,siz;
    }tr[maxn];
    int newnode(int k){
        tr[++idx].key=k; tr[idx].val=rand();
        tr[idx].cnt=1; tr[idx].siz=1;
        if(idx==1) rt=1;
        return idx;
    }
    void pushup(int u){
        tr[u].siz=tr[tr[u].l].siz+tr[tr[u].r].siz+tr[u].cnt;
    }
    void lturn(int &x){
        int y=tr[x].r;
        tr[x].r=tr[y].l; tr[y].l=x; x=y;
        pushup(tr[x].l); pushup(x);
    }
    void rturn(int &x){
        int y=tr[x].l;
        tr[x].l=tr[y].r; tr[y].r=x; x=y;
        pushup(tr[x].r); pushup(x);
    }
    void insert(int &x,int k){
        if(!x){
            x=newnode(k);
        }else if(tr[x].key==k){
            tr[x].cnt++;
        }else{
            if(k<tr[x].key){
                insert(tr[x].l,k);
                if(tr[tr[x].l].val>tr[x].val) rturn(x);
            }else{
                insert(tr[x].r,k);
                if(tr[tr[x].r].val>tr[x].val) lturn(x);
            }
        }
        pushup(x);
    }
    void del(int &x,int k){
        if(x==0){
            return;
        }if(tr[x].key==k){
            if(tr[x].cnt>1){
                tr[x].cnt--;
            }else{
                if(tr[x].l||tr[x].r){
                    if(!tr[x].r||tr[tr[x].l].val>tr[tr[x].r].val){
                        rturn(x);
                        del(tr[x].r,k);
                    }else{
                        lturn(x);
                        del(tr[x].l,k);
                    }
                }else{
                    x=0;
                    return;
                }       
            }
        }else if(k<tr[x].key){
            del(tr[x].l,k);
        }else{
            del(tr[x].r,k);
        }
        pushup(x);
    }
    int get_rank(int x,int k){
        if(x==0){
            return 1;
        }else if(tr[x].key==k){
            return tr[tr[x].l].siz+1;
        }else if(tr[x].key<k){
            return tr[tr[x].l].siz+tr[x].cnt+get_rank(tr[x].r,k);
        }else{
            return get_rank(tr[x].l,k);
        }
    }
    int get_key(int x,int rank){
        if(x==0){
            return inf;
        }else if(tr[tr[x].l].siz>=rank){
            return get_key(tr[x].l,rank);
        }else if(tr[tr[x].l].siz+tr[x].cnt>=rank){
            return tr[x].key;
        }else{
            return get_key(tr[x].r,rank-tr[x].cnt-tr[tr[x].l].siz);
        }
    }
    int get_prev(int x,int k){
        if(x==0){
            return -inf;
        }else if(tr[x].key>=k){
            return get_prev(tr[x].l,k);
        }else{
            return max(get_prev(tr[x].r,k),tr[x].key);
        }
    }
    int get_next(int x,int k){
        if(x==0){
            return inf;
        }else if(tr[x].key<=k){
            return get_next(tr[x].r,k);
        }else{
            return min(get_next(tr[x].l,k),tr[x].key);
        }
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
            bt.insert(bt.rt,x);
        }else if(opt==2){
            bt.del(bt.rt,x);
        }else if(opt==3){
            cout<<bt.get_rank(bt.rt,x)<<'\n';
        }else if(opt==4){
            cout<<bt.get_key(bt.rt,x)<<'\n';
        }else if(opt==5){
            cout<<bt.get_prev(bt.rt,x)<<'\n';
        }else{
            cout<<bt.get_next(bt.rt,x)<<'\n';
        }
    }
    return 0;
}