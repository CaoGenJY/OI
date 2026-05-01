#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int maxn=1e5+5;
struct node{
    int ls,rs;
    ull sum,tag;
    node(): ls(0),rs(0),sum(0),tag(0){}
}tr[maxn*64];
int nodes=1,root=0;
int newnode(){
    ++nodes;
    tr[nodes]=node();
    return nodes;
}
void maketag(int p,ull val,int len){
    tr[p].sum+=val*len;
    tr[p].tag+=val;
}
void pushdown(int p,int l,int r){
    if(!tr[p].tag) return;
    int mid=l+r>>1;
    if(!tr[p].ls) tr[p].ls=newnode();
    if(!tr[p].rs) tr[p].rs=newnode();
    maketag(tr[p].ls,tr[p].tag,mid-l+1);
    maketag(tr[p].rs,tr[p].tag,r-mid);
    tr[p].tag=0;
}
void pushup(int p){
    tr[p].sum=0;
    if(tr[p].ls) tr[p].sum+=tr[tr[p].ls].sum;
    if(tr[p].rs) tr[p].sum+=tr[tr[p].rs].sum;
}
void modify(int &p,int l,int r,int L,int R,ull v){
    if(!p) p=newnode();
    if(L<=l&&r<=R){
        maketag(p,v,r-l+1);
        return;
    }
    pushdown(p,l,r);
    int mid=l+r>>1;
    if(L<=mid) modify(tr[p].ls,l,mid,L,R,v);
    if(R>mid) modify(tr[p].rs,mid+1,r,L,R,v);
    pushup(p);
}
ull query(int p,int l,int r,int L,int R){
    if(!p) return 0;
    if(L<=l&&r<=R) return tr[p].sum;
    pushdown(p,l,r);
    int mid=l+r>>1;
    ull ret=0;
    if(L<=mid) ret+=query(tr[p].ls,l,mid,L,R);
    if(R>mid) ret+=query(tr[p].rs,mid+1,r,L,R);
    return ret;
}
int n,k,now;
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int pos; char c;
        cin>>pos>>c;
        if(c=='L') modify(1,1,)
    }
    return 0;
}