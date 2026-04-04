#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int d,n;
int hh=1,tt=0,q[maxn];
int a[maxn],b[maxn];
void debug(){
    cout<<hh<<' '<<tt<<'\n';
    for(int i=hh;i<=tt;i++) cout<<q[i]<<' ';
    cout<<'\n';
}
int find(int l,int r,int x){
    while(l<r){
        int mid=l+r>>1;
        if(q[mid]>=x){
            r=mid;
        }else l=mid+1;
    }
    return l;
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    memset(q,0,sizeof q);
    hh=1; tt=0;
    for(int t=1;t<=n;t++){
        // cout<<t<<'\n';
        for(int j=1;j<=a[t];j++) q[++tt]=t;
        // debug();
        hh+=b[t];
        // debug();
        int id=find(hh,tt,t-d+1);
        // cerr<<id<<'\n'; 
        hh=id;
        // debug();
    }
    cout<<tt-hh+1<<'\n';
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}