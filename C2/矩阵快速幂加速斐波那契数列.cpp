#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,mo;
struct matrix{
	ll a[5][5];
	matrix() {memset(a,0,sizeof a);}
	matrix operator *(const matrix &b){
		matrix ret;
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++){
				for(int k=1;k<=2;k++){
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
	cin>>n>>mo;
	if(n==1||n==2){
		cout<<1;
		return 0;
	}
	n-=2;
	a.a[1][1]=a.a[1][2]=1;
	b.a[1][2]=b.a[2][1]=b.a[2][2]=1;
	while(n){
		if(n&1) a=a*b;
		b=b*b;
		n>>=1;
	}
	cout<<a.a[1][2];
}