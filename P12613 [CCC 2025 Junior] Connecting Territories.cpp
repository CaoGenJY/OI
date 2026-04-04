#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#define ll long long
using namespace std;
const int maxn=2e4+4;
int n,m,k;
ll ans=0x3f3f3f3f,f[5][maxn];
void solve(){
    cin>>n>>m>>k;
    int h=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            h=((i-1)*m+j-1)%k+1;
            int yw=i&1;
            f[yw][j]=f[yw^1][j];
            if(j>1) f[yw][j]=min(f[yw][j],f[yw^1][j-1]);
            if(j<m) f[yw][j]=min(f[yw][j],f[yw^1][j+1]);
            f[yw][j]+=h;
            if(i==n) ans=min(ans,f[yw][j]);
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    int T=1; //cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000.0<<"ms\n";
    #endif
    return 0;
}