#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,org;
int a[maxn];
struct BIT{
    int tree[maxn];
    int lowbit(int x) {return x&(-x);}
    void init() {memset(tree,0,sizeof tree);}
    void add(int pos,int x){
        for(int i=pos;i<=n;i+=lowbit(i)){
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
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],a[i]++;
        org=0; b.init();
        for(int i=n;i>=1;i--){
            org+=b.query(a[i]);
            b.add(a[i],1);
        }
        int ans=org;
        for(int i=1;i<n;i++){
            org=org-(a[i]-1)+n-a[i];
            ans=min(ans,org);
        }
        cout<<ans<<'\n';        
    }
    return 0;
}