	#include<bits/stdc++.h>
	using namespace std;
	const int maxn=3e5+5;
	struct node{
		int m1,m2;
		node operator +(const node &y) const{
			node ret;
			if(m1>=y.m1){
				ret.m1=m1;
				ret.m2=max(m2,max(y.m1,y.m2));
			}else{
				ret.m1=y.m1;
				ret.m2=max(m1,max(m2,y.m2));
			}
			return ret;
		}
	}f[maxn];
	int n,ans[maxn];
	int main(){
		freopen("f.in","r",stdin);
		freopen("f.out","w",stdout);
		cin.tie(0)->ios::sync_with_stdio(false);
		cin>>n;
		for(int i=0;i<(1<<n);i++){
			cin>>f[i].m1; f[i].m2=-0x3f3f3f3f;
		}
		for(int j=1;j<=n;j++){
			for(int i=0;i<(1<<n);i++){
				if((i>>(j-1))&1){
					f[i]=f[i]+f[i^(1<<(j-1))];
				}
			}
		}
		for(int i=1;i<(1<<n);i++){
			ans[i]=max(ans[i-1],f[i].m1+f[i].m2);
		}
		for(int i=1;i<(1<<n);i++){
			cout<<ans[i]<<'\n';
		}
		return 0;
	}