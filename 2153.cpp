#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mo=1e9+7;
ll qmi(ll x,ll p){
	ll ret=1;
	while(p){
		if(p&1) ret=ret*x%mo;
		x=x*x%mo;
		p>>=1;
	}
	return ret;
}
ll n,P;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("0in.in","r",stdin);
	#endif
	cin>>P>>n;
	ll a=qmi(P-1,n);
	ll b=((P-1)%mo*((n&1)?mo-1:1))%mo;
	ll c=qmi(P,mo-2);
	cout<<((a+b)%mo*c)%mo;
	return 0;
}