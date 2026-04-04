#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,top,ans;
int a[maxn],vis[maxn],stk[maxn],tmp[maxn];
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n*2;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n*2;i++){
        if(vis[a[i]]){
            int ttop=0;
            while(stk[top]!=a[i]){
                tmp[++ttop]=stk[top];
                top--;
                ans++;
            }
            top--;
            while(ttop) stk[++top]=tmp[ttop--];
        }else{
            vis[a[i]]=1;
            stk[++top]=a[i];
        }
    }
    cout<<ans<<'\n';
    return 0;
}