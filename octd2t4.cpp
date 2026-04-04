#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+6;
int n,asum;
int a[105],b[105],dp[maxn],nxt[maxn];
int main(){
	freopen("cooperate.in", "r", stdin);
	freopen("cooperate.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        asum+=a[i];
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        memset(nxt,0x3f,sizeof nxt);
        for(int t=0;t<=asum;t++){
            if(dp[t]!=0x3f3f3f3f){
                if(t+a[i]<=asum){
                    nxt[t+a[i]]=min(nxt[t+a[i]],dp[t]);
                }
                nxt[t]=min(nxt[t],dp[t]+b[i]);                
            }
        }
        for(int t=0;t<=asum;t++) dp[t]=nxt[t];
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=asum;i++){
        ans=min(ans,max(i,dp[i]));
    }
    cout<<ans;
    return 0;
}
/*
dp[i+1][t+a[i]]=min(dp[i+1][t+a[i]],dp[i][t])
dp[i+1][t]=min(dp[i+1][t],dp[i][t]+b[i])
*/