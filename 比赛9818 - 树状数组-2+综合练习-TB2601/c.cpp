#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,ans[maxn];
struct BIT{
    int tree[maxn];
    int lowbit(int x) {return x&(-x);}
    void init() {memset(tree,0,sizeof tree);}
    void add(int pos,int x){
        for(int i=pos;i<=1e5+3;i+=lowbit(i)){
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
struct node{
    int x,y,id;
}a[maxn];
bool cmp(node x,node y){
    if(x.x==y.x) return x.y>y.y;
    return x.x<y.x;
}
int main(){
    int T; cin>>T;
    for(int cs=1;cs<=T;cs++){
        cin>>n; b.init();
        for(int i=1;i<=n;i++){
            int x,y; cin>>x>>y;
            a[i].x=x; a[i].y=y; a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(!(a[i].x==a[i-1].x)||!(a[i].y==a[i-1].y)){
                ans[a[i].id]=b.query(1e5+3)-b.query(a[i].y-1);
            }else ans[a[i].id]=ans[a[i-1].id];
            b.add(a[i].y,1);
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';
        cout<<'\n';
    }
    return 0;
}