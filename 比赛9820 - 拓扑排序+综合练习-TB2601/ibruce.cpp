//niiick
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int read()
{
    int x=0,f=1;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return x*f;
}

const int mod=10007;
const int maxn=50010;
int n,m,mx,ans;
int a[maxn],sum[maxn];
int dp[maxn],S[maxn];
int rem[maxn];

int check(int x)
{
    int tot=0,len=0;
    for(int i=1;i<=n;++i)
    {
        if(len+a[i]>x) tot++,len=a[i];
        else len+=a[i];
        if(tot>m) return 0;
    }
    return tot<=m;
}

int DP(int x)
{
    int k=0;
    for(int i=1;i<=n;++i)
    for(;k<i;++k)
    if(sum[i]-sum[k]<=x){ rem[i]=k; break;}
    
    int res=(sum[n]<=x);
    for(int i=1;i<=n;++i)
    {
    	if(sum[i]<=x) dp[i]=1;
    	S[i]=(S[i-1]+dp[i])%mod;
    }
    
    for(int i=2;i<=m+1;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dp[j]=S[j-1];
            if(rem[j]-1>=0) dp[j]=((dp[j]-S[rem[j]-1])%mod+mod)%mod;//注意减法出现负数
        }
        for(int j=1;j<=n;++j)
        S[j]=(S[j-1]+dp[j])%mod;
        
        res=(res+dp[n])%mod;
    }
    return res;
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) 
    a[i]=read(),sum[i]=sum[i-1]+a[i],mx=max(mx,a[i]);
    
    int L=mx,R=sum[n],mid;
    while(L<R)
    {
        mid=L+R>>1;
        if(check(mid)) ans=mid,R=mid;
        else L=mid+1;
    }
    printf("%d %d",ans,DP(ans));
    return 0;
}
