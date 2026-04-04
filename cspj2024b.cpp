#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+3;
int T,n,m,k,x,y,dir;
char mp[maxn][maxn];
int vis[maxn][maxn];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	// freopen("0in.in","r",stdin);
	cin>>T;
	while(T--){
		int ans=1;
		memset(vis,0,sizeof vis);
		cin>>n>>m>>k>>x>>y>>dir;
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		while(k--){
			int nx=x+dx[dir],ny=y+dy[dir];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
				if(!vis[nx][ny]){
					vis[nx][ny]=1;
					ans++;
				}
				x=nx,y=ny;
			}else (dir+=1)%=4;
		}
		cout<<ans<<'\n';
	}
	return 0;
}