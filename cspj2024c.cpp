#include<bits/stdc++.h>
using namespace std;
int ys[15]={6,2,5,5,4,5,6,3,7,6};
vector<int> v;
int n;
bool dfs(int now){
	if(now==n) return true;
	if(now>n) return false;
	for(int i=0;i<=9;i++){
		if(now+ys[i]<=n){
			v.push_back(i);
			if(dfs(now+ys[i])) return true;
			v.pop_back();
		}
	}
	return false;
}
int main(){
	freopen("0in.in","r",stdin);
	int T;
	cin>>T;
	while(T--){
		bool flg=false;
		cin>>n;
		v.clear();
		for(int i=1;i<=9;i++){
			v.push_back(i);
			if(dfs(ys[i])){
				for(const auto &it:v) cout<<it;
				flg=true;
				break;
			}
			v.pop_back();
		}
		if(!flg) cout<<-1;
		puts("");
	}
	return 0;
}