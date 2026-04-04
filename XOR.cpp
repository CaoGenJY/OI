#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+6;
int tree[maxn][5],ed[maxn],tmp[maxn];
void turn(int x){
    for(int i=31;i>=1;i--){
        tmp[32-i]=(x>>(i-1))&1;
    }
}
int idx=0;
void insert(){
    int p=0;
    for(int i=1;i<=31;i++){
        int now=tmp[i];
        if(!tree[p][now]) tree[p][now]=++idx;
        p=tree[p][now];
    }
    ed[idx]=1;
}
int find(){
    int p=0,ret=0;
    for(int i=1;i<=31;i++){
        int now=tmp[i];
        int tt=now^1;
        if(tree[p][tt]) ret|=(1<<(31-i)),p=tree[p][tt];
        else p=tree[p][now];
    }
    return ret;
}
int n;
int a[maxn];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        turn(a[i]);
        insert();
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        turn(a[i]);
        ans=max(ans,find());
        // cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}