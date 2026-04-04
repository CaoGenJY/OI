#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+6;
int n,m,c,lst,ans;
int a[maxn];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("0in.in","r",stdin);
	#endif
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i+n]=a[i]+m;
	int j=2;
	for(int i=1;i<=n+1;i++){
		while(j<=n*2&&(j-i<c||a[j]==a[j-1])) j++;
		ans+=(min(a[i],m)-lst)*(j-i);
		lst=min(a[i],m);
	}
	cout<<ans;
	return 0;
}