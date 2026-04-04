#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,ans,k;
int dis[maxn],a[maxn];
vector<int> to[maxn];
void dfs(int u,int f){
    for(const auto &v:to[u]){
        if(v==f) continue;
        dfs(v,u);
        dis[u]=max(dis[u],dis[v]+1);
    }
    if(dis[u]==k-1&&u!=1&&f!=1){
        dis[u]=-1;
        ans++;
    }
}
int main(){
    cin>>n>>k;
    cin>>a[1]; if(a[1]!=1) ans++;
    for(int i=2;i<n;i++){
        cin>>a[i];
        to[a[i]].push_back(i);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}