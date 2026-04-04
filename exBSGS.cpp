#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ksm(ll a,ll k,ll p){
	ll ret=1;
	while(k){
		if(k&1) ret=ret*a%p;
		a=a*a%p;
		k>>=1;
	}
	return ret;
}
ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}
unordered_map<int,int> hsh;
ll exBSGS(ll a,ll b,ll p){
	if(b==1||p==1) return 0;
	ll g,A=1,k=0;
	while((g=gcd(a,p))!=1){
		if(b%g) return -1;
		b/=g; p/=g;
		A=A*(a/g)%p;
		k++;
		if(A==b) return k;
	}
	hsh.clear();
	ll m=(double)(sqrt(p)+1),baby=b%p;
	for(int i=0;i<m;i++){
		hsh[baby]=i;
		baby=baby*a%p;
	}
	ll am=ksm(a,m,p),cur=am*A%p;
	for(int i=1;i<=m;i++){
		if(hsh.count(cur)){
			return i*m-hsh[cur]+k;
		}
		cur=cur*am%p;
	}
	return -1;
}
void solve(ll a,ll b,ll p){
    ll ans=exBSGS(a,b,p);
    if(ans==-1){
    	cout<<"No Solution\n";
    }else{
    	cout<<ans<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    ll a,b,p;
    while(true){
    	cin>>a>>p>>b;
    	if(a==0&&b==0&&p==0) break;
        solve(a%p,b%p,p);
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000.0<<"ms\n";
    #endif
    return 0;
}