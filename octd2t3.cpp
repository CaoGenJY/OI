#include<bits/stdc++.h>
using namespace std;
const int maxn=105,maxm=1e5+5;
int n,m,V;
int v[maxn],w[maxn],dp[maxn][maxm];
bool check(int type){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    if(type==1) return dp[n][m]>=V;
    return dp[n][m]<=V;
}
int main(){
	freopen("pack.in","r",stdin);
    freopen("pack.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    cin>>V;
    int l=1,r=1e5,ans=1;
    while(l<=r){
        m=(l+r)>>1;
        if(check(1)){
            ans=m;
            r=m-1;
        }else l=m+1;
    }
    cout<<ans<<endl;
    l=1,r=1e5;
    while(l<=r){
        m=(l+r)>>1;
        if(check(2)){
            ans=m;
            l=m+1;
        }else r=m-1;
    }
    if(ans==100000) puts("inf");
    else cout<<ans<<endl;
    return 0;
}
