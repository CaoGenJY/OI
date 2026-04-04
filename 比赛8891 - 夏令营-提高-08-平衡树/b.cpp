#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+4,inf=1e8;
int readu(){int k=0,f=1; char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9') k=k*10+ch-'0',ch=getchar();return k*f;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x<10)putchar(x+'0');else write(x/10),putchar(x%10+'0');}
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
        }else if(tr[x].key==k){
            return k;   
        }else if(tr[x].key>k){
            return get_prev(tr[x].l,k);
        }else{
            return max(get_prev(tr[x].r,k),tr[x].key);
        }
    }
    int get_next(int x,int k){
        if(x==0){
            return inf;
        }else if(tr[x].key==k){
            return k;   
        }else if(tr[x].key<k){
            return get_next(tr[x].r,k);
        }else{
            return min(get_next(tr[x].l,k),tr[x].key);
        }
    }
}bt;
int n,m,x,top;
char opt;
int stk[maxn];
int main(){
    srand(114514);
    n=readu(); m=readu();
    bt.insert(bt.rt,0);
    bt.insert(bt.rt,n+1);
    for(int i=1;i<=m;i++){
        cin>>opt;
        if(opt=='D'){
            x=readu();
            bt.insert(bt.rt,x);
            stk[++top]=x;
        }else if(opt=='R'){
            bt.del(bt.rt,stk[top--]);
        }else{
            x=readu();
            int l=bt.get_prev(bt.rt,x);
            int r=bt.get_next(bt.rt,x);
            if(l==r){
                write(0); puts("");
            }else{
                write(r-l-1); puts("");
            }
        }
    }
    return 0;
}