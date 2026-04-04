#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	// freopen("0in.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		if(i<=m) puts("OK");
		else puts("Too Many Requests");
	}
	return 0;
}