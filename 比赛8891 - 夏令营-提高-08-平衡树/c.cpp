#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5,inf=0x3f3f3f3f;
int ans=0;
struct Treap{
    int idx=0,rt=0;
    struct node{
        int l,r;
        int key,val;
        int cnt,siz;
        int lzy;
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
    void pushdown(int u){
        tr[tr[u].l].key+=tr[u].lzy;
        tr[tr[u].r].key+=tr[u].lzy;
        tr[tr[u].l].lzy+=tr[u].lzy;
        tr[tr[u].r].lzy+=tr[u].lzy;
        tr[u].lzy=0;
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
        }else{
            pushdown(x);
            if(tr[x].key==k){
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
        }
        pushup(x);
    }
    void del(int &x,int k){
        if(x==0){
            return;
        }else{
            pushdown(x);
            if(tr[x].key==k){
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
        }
        pushup(x);
    }
    int get_key(int x,int rank){
        if(x==0){
            return inf;
        }else{
            pushdown(x);
            if(tr[tr[x].l].siz>=rank){
                return get_key(tr[x].l,rank);
            }else if(tr[tr[x].l].siz+tr[x].cnt>=rank){
                return tr[x].key;
            }else{
                return get_key(tr[x].r,rank-tr[x].cnt-tr[tr[x].l].siz);
            }
        }
    }
    void update(int &x,int k){
        if(x==0)return;
        pushdown(x);
        if(tr[x].key<k){
            ans+=tr[tr[x].l].siz+tr[x].cnt; 
            int rst=tr[x].r;
            x=0;
            update(rst,k);
            x=rst;
        }else{
            update(tr[x].l,k);
            pushup(x);
        }
    }
}bt;
int n,minn,x;
char opt;
int main(){
    srand(114514);
    cin.tie(0)->ios::sync_with_stdio(false); cout.tie(0);
    cin>>n>>minn;
    for(int i=1;i<=n;i++){
        cin>>opt>>x;
        if(opt=='I'){
            if(x>=minn)bt.insert(bt.rt,x);
        }else if(opt=='A'){
            bt.tr[bt.rt].lzy+=x;
            bt.tr[bt.rt].key+=x;
            bt.update(bt.rt,minn);
        }else if(opt=='S'){
            bt.tr[bt.rt].lzy-=x;
            bt.tr[bt.rt].key-=x;
            bt.update(bt.rt,minn);
        }else{
            if(x>bt.tr[bt.rt].siz)cout<<-1<<'\n';
            else cout<<bt.get_key(bt.rt,bt.tr[bt.rt].siz-x+1)<<'\n';
        }
    }
    cout<<ans<<'\n';
    return 0;
}
