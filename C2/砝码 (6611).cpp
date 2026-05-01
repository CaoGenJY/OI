#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,ccnt;
int a[maxn],b[maxn],c[maxn],d[maxn];
map<int,int> pos;
bool dfs(int cur){
    if(cur>ccnt){
        return false;
    }else if(d[cur]){
        d[cur]--;
        return true;
    }else if(dfs(cur+1)){
        d[cur]=c[cur+1]/c[cur]-1;
        return true;
    }else return false;
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(b+1,b+m+1);
    for(int i=1;i<=m;i++){
        if(b[i]!=b[i-1]) c[++ccnt]=b[i];
        pos[b[i]]=ccnt;
    }
    for(int i=1;i<=n;i++){
        for(int j=ccnt;j>=1;j--){
            d[j]+=a[i]/c[j];
            a[i]%=c[j];
        }
    }
    for(int i=1;i<=m;i++){
        if(!dfs(pos[b[i]])){
            cout<<i-1;
            return 0;
        }
        if(i==m) cout<<m;
    }
    return 0;
}