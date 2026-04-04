#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e7+50;
bool vis[maxn];
int b[maxn],idx;
bool p(int x){
	while(x){
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
inline ll read(){
	ll _a=0,_ne=1;
    char _c=getchar();
    while(!isdigit(_c)){
        if(_c=='-')_ne=-1;
        _c=getchar();
    }
    while(_c>='0'&&_c<='9'){
    	_a=(_a<<1)+(_a<<3)+(_c^48);
		_c=getchar();
	}
    return _a*_ne;
}
inline void write(ll _a){
	if(_a<0){
		putchar('-');
		_a*=-1;
	} 
	if(_a>9)write(_a/10);
	putchar(_a%10+'0');
}
int main(){
	// freopen("number.in","r",stdin);
	// freopen("number.out","w",stdout);
	for(int i=1;i<=maxn;i++){
		if(p(i)){
			for(int j=i;j<=maxn;j+=i){
				vis[j]=1;
			}
		}
	}
    for(int i=1;i<=maxn;i++){
        if(!vis[i]) b[++idx]=i;
    }
	int T;
	cin>>T;
	while(T--){
		int x=read();
        if(vis[x]) write(-1);
        else write(*(upper_bound(b+1,b+idx+1,x)));
        puts("");
	} 
	return 0;
}