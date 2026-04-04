#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m;
int a[maxn];
int main(){
	freopen("0in.in","r",stdin);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++) if(sum-a[i]==m){puts("Yes");return 0;}
	puts("No");
	return 0;
}