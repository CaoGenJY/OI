#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+4,maxm=1e6+6;
int n,m,k,cst[20],ans;
vector<int> kk[20];
struct edge{
	int u,v,w;
}e[maxm];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
	}
	for(int i=1;i<=k;i++){
		cin>>cst[i];
		for(int j=1;j<=n;j++){
			int v;
			cin>>v;
			to[i].push_back(v);
		}
	}
	int smax=1<<k;
	for(int s=1;s<smax;s++){
		ans=0;
		for(int j=0;j<k;j++){
			if((s>>j)&1){
				ans+=cst[j+1];
				to[]
			}
		}
	}
}