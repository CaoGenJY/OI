#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,idx;
int a[maxn],tong[maxn];
map<int,int> mp;
signed main(){
	freopen("0in.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!mp.count(a[i])) mp[a[i]]=++idx;
		tong[mp[a[i]]]++;
	}
	int ans=0;
	for(int i=1;i<=idx;i++){
		if(tong[i]>=2) ans+=tong[i]*(tong[i]-1)/2*(n-tong[i]);
	}
	cout<<ans;
	return 0;
}