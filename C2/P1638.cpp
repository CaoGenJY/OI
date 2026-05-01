#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+6,maxk=2e3+3;
int n,m;
int a[maxn],vis[maxk];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int lp=1,rp=1,num=1,ans=0x3f3f3f3f,ansl=0,ansr=0;
    vis[a[1]]=1;
    while(lp<=n&&rp<=n){
        if(num==m){
            if(ans>(rp-lp+1)){
                ans=rp-lp+1;
                ansl=lp;
                ansr=rp;
            }
            vis[a[lp]]--;
            if(!vis[a[lp]]) num--;
            lp++;
        }else{
            rp++;
            if(!vis[a[rp]]) num++;
            vis[a[rp]]++;
        }
    }
    cout<<ansl<<' '<<ansr;
    return 0;
}