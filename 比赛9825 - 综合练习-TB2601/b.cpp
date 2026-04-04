#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
struct city{
    int id,fd;
    bool operator <(const city &y) const{
        return fd>y.fd;
    }
};
priority_queue<city> pq[maxn];
int ans1[maxn],ans2[maxn];
int ws(int x){
    int ret=0;
    while(x){
        ret++;
        x/=10;
    }
    return ret;
}
void out(int x){
    for(int j=1;j<=6-ws(x);j++) cout<<0;
    cout<<x;
}
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int p,fd; cin>>p>>fd;
        pq[p].push({i,fd});
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        while(!pq[i].empty()){
            city ft=pq[i].top(); pq[i].pop();
            ans1[ft.id]=i; ans2[ft.id]=++cnt;
        }
    }
    for(int i=1;i<=m;i++){
        out(ans1[i]); out(ans2[i]); cout<<'\n';
    }
    return 0;
}