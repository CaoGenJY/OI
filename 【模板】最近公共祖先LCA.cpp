#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
struct ST_Table{
	static const int maxk=50;
	int st[maxn][maxk],lg[maxn];
	void build(int *a){
		lg[1]=0;
		for(int i=1;i<=n;i++){
			lg[i]=lg[i>>1]+1;
		}
		memset(st,0x3f,sizeof st);
		for(int i=1;i<=n;i++){
			st[i][0]=a[i];
		}
		for(int j=1;j<=lg[n];j++){
			for(int i=1;i<=(n-(1<<j)+1);i++){
				st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
			}
		}
	}
	int query(int l,int r){
		int k=lg[y-x+1];
		return min(st[l][k],st[r-(1<<k)+1][k]);
	}
}st;
vector<int> to[maxn];
int dfn[maxn],idx;
void dfs(int u,int f){
	dfs[u]=idx++;
	for(const auto &v:to[u]){
		if(v==f) continue;
		
	}
}
void solve(){
    
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
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