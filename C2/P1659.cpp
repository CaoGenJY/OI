#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
using ll=unsigned long long;
const int maxn=2e6+6,mod=19930726;
int n,k,cnt;
int p[maxn],ccnt[maxn];
char ch[maxn],s[maxn];
void build(){
    int len=strlen(ch);
    s[++cnt]='~'; s[++cnt]='#';
    for(int i=0;i<len;i++){
        s[++cnt]=ch[i];
        s[++cnt]='#';
    }
    s[++cnt]='!';
}
void manacher(){
    build();
    int len=strlen(s);
    int mr=0,mid=0;
    for(int i=2;i<cnt;i++){
        if(i<=mr) p[i]=min(p[mid*2-i],mr-i+1);
        else p[i]=1;
        while(s[i-p[i]]==s[i+p[i]]) p[i]++;
        if(i+p[i]>mr) mr=i+p[i]-1,mid=i;
        ccnt[p[i]-1]++;
    }
}
ll ksm(ll a,ll k){
    ll ret=1;
    while(k){
        if(k&1) ret=ret*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return ret;
}
signed main(){
    ll ans=1;
    cin>>n>>k>>ch;
    manacher();
    int sum=0;
    for(int i=n;i>=1;i--)
        if(i%2){
            sum+=ccnt[i];
            if(sum<k){
                ans*=ksm(i,sum);
                ans%=mod;
                k-=sum;
            }else{
                ans*=ksm(i,k);
                ans%=mod;
                k=0;
                break;
            }
        }
    if(k>0) puts("-1");
    else cout<<ans;
    return 0;
}