#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mo=1e9+7;
ll n,k;
struct matrix {
	ll a[105][105];
	matrix() {memset(a,0,sizeof a);}
	matrix operator *(const matrix &b) {
		matrix ret;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				for(int k=1;k<=n;k++) {
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j]%mo)%mo;
				}
			}
		}
		return ret;
	}
} base,a;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("0in.in","r",stdin);
	#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			int x;cin>>x;
			a.a[i][j]=x;
		}
	}
	for(int i=1;i<=n;i++) {
		base.a[i][i]=1;
	}
	while(k) {
		if(k&1) base=base*a;
		a=a*a;
		k>>=1;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout<<base.a[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}