#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=105,P=131;
string s;
ull h[maxn],p[maxn],dp[maxn][maxn];
void build(){
    p[0]=1;
    for(int i=0;i<(int)s.size();i++){
        p[i+1]=p[i]*P;
        h[i+1]=h[i]*P+s[i];
    }
}
ull query(int l,int r){
    return h[r+1]-h[l]*p[r-l+1];
}
int ws(int x){
    int ret=0;
    while(x){
        ret++;
        x/=10;
    }
    return ret;
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>s; int n=s.size();
    build();
    for(int i=0;i<n;i++) memset(dp[i],0x3f,sizeof dp[i]);
    for(int len=1;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1; dp[i][j]=len;
            for(int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            for(int k=1;k<len;k++){
                if(len%k) continue;
                int num=len/k;
                ull hh=query(i,i+k-1);
                bool flg=true;
                for(int u=i+k;u<=j;u+=k){
                    if(query(u,u+k-1)!=hh){
                        flg=false;
                        break;
                    }
                }
                if(flg){
                    for(int u=i;u<=j;u+=k){
                        dp[i][j]=min(dp[i][j],(ull)(2+ws(num)+dp[u][u+k-1]));
                    }
                    dp[i][j]=min(dp[i][j],(ull)(2+k+ws(num)));
                }
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
/*
0 1 2 3 4 5
0->2->4
*/