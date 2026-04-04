#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int ans,n;
int vis[maxn];
string S,s[maxn];
void dfs(int u,string now){
    if(u==n+1){
        int tmp=0,ret=0;
        for(int i=0;i<now.size();i++){
            if(now[i]=='(') tmp++;
            else if(tmp) tmp--,ret+=2;
        }
        ans=max(ans,ret);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        dfs(u+1,now+s[i]);
        vis[i]=0;
    }
}
int main(){
	freopen("parentheses.in", "r", stdin);
	freopen("parentheses.out", "w", stdout);
    cin>>n>>S;
    for(int i=1;i<=n;i++){
        s[i]=S.substr(0,i);
    }
    dfs(1,"");
    cout<<ans;
    return 0;
}