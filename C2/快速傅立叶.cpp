#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cmath>
#include<complex>
using namespace std;
typedef complex<double> cp;
const double pi=acos(-1);
const int maxn=2097153;
int rev[maxn];
void init(int len,int k){
    for(int i=0;i<len;i++){
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
    }
}
void FFT(cp *a,int n,int flg){
    for(int i=0;i<n;i++){
        if(i<rev[i]) swap(a[i],a[rev[i]]);
    }
    for(int h=1;h<n;h<<=1){
        cp wn(cos(flg*pi/h),sin(flg*pi/h));
        for(int j=0;j<n;j+=(h<<1)){
            cp now(1,0);
            for(int k=j;k<j+h;k++){
                cp x=a[k],y=now*a[k+h];
                a[k]=x+y; a[k+h]=x-y;
                now*=wn;
            }
        }
    }
    if(flg==-1){
        for(int i=0;i<n;i++){
            a[i]/=n;
        }
    }
    return;
}
cp a[maxn],b[maxn];
int ans[maxn];
void solve(){
    int n; string s1,s2; cin>>n>>s1>>s2;
    for(int i=0;i<s1.size();i++){
        a[i]=double(s1[(int)s1.size()-i-1]-'0');
    }
    for(int i=0;i<s2.size();i++){
        b[i]=double(s2[(int)s2.size()-i-1]-'0');
    }
    int lmt=1,k=0;
    while(lmt<(int)s1.size()+(int)s2.size()){
        lmt<<=1; k++;
    }
    init(lmt,k);
    FFT(a,lmt,1);
    FFT(b,lmt,1);
    for(int i=0;i<lmt;i++) a[i]*=b[i];
    FFT(a,lmt,-1);
    for(int i=0;i<lmt;i++){
        ans[i]+=(int)(a[i].real()+0.5);
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    while(!ans[lmt]&&lmt>-1) lmt--;
    if(lmt==-1) cout<<"0\n";
    else{
        for(int i=lmt;i>=0;i--) cout<<ans[i];
    }
    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    // #ifndef ONLINE_JUDGE
    freopen("fft.in","r",stdin);
    freopen("fft.out","w",stdout);
    // #endif
    int T=1; //cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000.0<<"ms\n";
    #endif
    return 0;
}