#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mo=1e9+7;
ll n;
struct matrix{
	ll a[5][5];
	matrix() {memset(a,0,sizeof a);}
	matrix operator *(const matrix &b){
		matrix ret;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j]%mo)%mo;
				}
			}
		}
		return ret;
	}
}a,b;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("0in.in","r",stdin);
	#endif
	int T;cin>>T;
	while(T--){
		cin>>n;
		if(n==1||n==2||n==3){
			cout<<"1\n";
			continue;
		}
		n-=3;
		a=matrix();b=matrix();
		a.a[1][1]=a.a[1][2]=a.a[1][3]=1;
		b.a[1][3]=b.a[2][1]=b.a[3][2]=b.a[3][3]=1;
		while(n){
			if(n&1) a=a*b;
			b=b*b;
			n>>=1;
		}
		cout<<a.a[1][3]<<'\n';		
	}
	return 0;
}