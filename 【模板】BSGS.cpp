#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ksm(ll a,ll k,ll p){
    ll ret=1;
    while(k){
        if(k&1) ret=ret*a%p;
        a=a*a%p;
        k>>=1;
    }
    return ret;
}
map<int,int> hsh;
int BSGS(ll a,ll b,ll p){
    if(b%p==1) return 0;
    hsh.clear();
    ll m=(double)(sqrt(p)+1),baby=b%p;
    for(int i=0;i<m;i++){
        hsh[baby]=i;
        baby=baby*a%p;
    }
    ll am=ksm(a,m,p),cur=am;
    for(int i=1;i<=m;i++){
        if(hsh.count(cur)){
            return i*m-hsh[cur];
        }
        cur=cur*am%p;
    }
    return -1;
}
void solve(ll a,ll b,ll p){
    ll ans=BSGS(a,b,p);
    if(ans==-1){
        cout<<"no solution\n";
    }else{
        cout<<ans<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    ll a,b,p;
    while(cin>>p>>a>>b){
        solve(a,b,p);
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n";
    #endif
    return 0;
}