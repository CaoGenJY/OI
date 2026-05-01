#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+5;
int idx;
char tmp[maxn];
int tree[maxn][65],cnt[maxn];
int getnum(char c){
	if(c>='A'&&c<='Z') return c-'A';
	else if(c>='a'&&c<='z') return c-'a'+26;
	return c-'0'+52;
}
void insert(char ch[]){
	int p=0,len=strlen(ch);
	for(int i=0;i<len;i++){
		int now=getnum(ch[i]);
		if(!tree[p][now]){
			tree[p][now]=++idx;
		}
		p=tree[p][now];
		cnt[p]++;
	}
}
int find(char ch[]){
	int p=0,len=strlen(ch);
	for(int i=0;i<len;i++){
		int now=getnum(ch[i]);
		if(!tree[p][now]) return 0;
		p=tree[p][now];
	}
	return cnt[p];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("0in.in","r",stdin);
	#endif
	int T;
	cin>>T;
	while(T--){
		for(int i=0;i<=idx;i++){
			cnt[i]=0;
			for(int j=0;j<=64;j++){
				tree[i][j]=0;
			}
		}
		idx=0;
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>tmp;
			insert(tmp);
		}
		for(int i=1;i<=m;i++){
			cin>>tmp;
			cout<<find(tmp)<<endl;
		}
	}
	return 0;
}