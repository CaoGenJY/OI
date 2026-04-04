#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cp;
typedef long long ll;
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
ll sa[maxn],sb[maxn],saf,sbf,sua,sub,n,m,maxx;
void get_corr(ll n1,ll n2){
	ll lmt=1,k=0;
	while(lmt<n1+n2){
		lmt<<=1; k++;
	}
	init(lmt,k);
	FFT(a,lmt,1);
	FFT(b,lmt,1);
	for(int i=0;i<lmt;i++) a[i]*=b[i];
	FFT(a,lmt,-1);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>sa[i];
    	saf+=sa[i]*sa[i];
    	sua+=sa[i];
    }
    for(int i=1;i<=n;i++){
    	cin>>sb[i];
    	sbf+=sb[i]*sb[i];
    	sub+=sb[i];
    }
    for(int i=0;i<n;i++) a[i]=a[i+n]=sa[i+1];
    for(int i=0;i<n;i++) b[i]=sb[n-i];
    get_corr(n<<1,n);
	for(int i=n-1;i<(n<<1);i++){
		maxx=max(maxx,ll(a[i].real()+0.5));
	}
	ll c0=(sub-sua)/n,minn=0x3f3f3f3f;
    ll A=n,B=2*(sua-sub);
    ll x1=floor(-(double)B/2.0/A),x2 = ceil(-(double)B/2.0/A);
    minn=min(minn,A*x1*x1+B*x1);
    minn=min(minn,A*x2*x2 +B*x2);
	cout<<saf+sbf+minn-2*maxx<<'\n';
	return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    #ifdef ONLINE_JUDGE
    freopen("gift.in","r",stdin);
    freopen("gift.out","w",stdout);
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
