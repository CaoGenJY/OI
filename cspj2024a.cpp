#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
map<pair<char,char>,bool> mp;
int main(){
	// freopen("0in.in","r",stdin);
	cin>>n;
	while(n--){
		char a,b;
		cin>>a>>b;
		if(!mp.count(make_pair(a,b))){
			ans--;
			mp[make_pair(a,b)]=1;
		}
	}
	cout<<ans;
	return 0;
}