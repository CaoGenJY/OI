#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,q;
int ans[maxn];
struct BIT{
    int tree[maxn];
    int lowbit(int x){return x&(-x);}
    void init(){memset(tree,0,sizeof tree);}
    void add(int pos,int x){
        for(int i=pos;i<=n+5;i+=lowbit(i)){
            tree[i]+=x;
        }
    }
    int query(int pos){
        int ret=0;
        for(int i=pos;i>0;i-=lowbit(i)){
            ret+=tree[i];
        }
        return ret;
    }
}b;
struct Blk{
    int l,r;
}a[maxn];
struct Query{
    int l,r,id;
}qu[maxn];
bool cmp1(Blk x,Blk y){
    if(x.l==y.l) return x.r>y.r;
    return x.l>y.l;
}
bool cmp2(Query x,Query y){
    if(x.l==y.l) return x.r>y.r;
    return x.l>y.l;
}
int main(){
    freopen("e.in","r",stdin);
    freopen("e.out","w",stdout);
    cin>>n>>m>>q;b.init();
    for(int i=1;i<=m;i++){
        cin>>a[i].l>>a[i].r;
    }
    for(int i=1;i<=q;i++){
        cin>>qu[i].l>>qu[i].r;qu[i].id=i;
    }
    sort(a+1,a+m+1,cmp1);
    sort(qu+1,qu+q+1,cmp2);
    int j=1;
    for(int i=1;i<=q;i++){
        while(j<=m&&a[j].l>=qu[i].l){
            b.add(a[j].r,1);
            j++;
        }
        ans[qu[i].id]=b.query(qu[i].r);
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
    return 0;
}
