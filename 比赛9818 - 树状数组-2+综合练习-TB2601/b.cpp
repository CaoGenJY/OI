#include<bits/stdc++.h>
using namespace std;
const int maxn=800005;
int n,m,k;
struct BIT{
    long long tree[maxn];
    int lowbit(int x) {return x&(-x);}
    void init() {memset(tree,0,sizeof tree);}
    void add(int pos,int x){
        for(int i=pos;i<=m;i+=lowbit(i)){
            tree[i]+=x;
        }
    }
    long long query(int pos){
        long long ret=0;
        for(int i=pos;i>0;i-=lowbit(i)){
            ret+=tree[i];
        }
        return ret;
    }
}b;
pair<int,int> a[maxn];
int main(){
    int T; cin>>T;
    for(int cs=1;cs<=T;cs++){
        cin>>n>>m>>k;
        b.init();
        for(int i=1;i<=k;i++){
            int u,v; cin>>u>>v;
            a[i].first=u,a[i].second=v;
        }
        sort(a+1,a+k+1);
        long long ans=0;
        for(int i=k;i>=1;i--){
            ans+=b.query(a[i].second-1);
            b.add(a[i].second,1);
        }
        printf("Test case %d: %lld\n",cs,ans);
    }
    return 0;
}