#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll c[10],d[10],tot,s,t,f[maxn];
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>c[1]>>c[2]>>c[3]>>c[4]>>tot;
    f[0]=1;
    for(int i=1;i<=4;i++){
        for(int j=c[i];j<=maxn;j++){
            f[j]+=f[j-c[i]];
        }
    }
    while(tot--){
        cin>>d[1]>>d[2]>>d[3]>>d[4]>>s;
        ll ans=f[s];
        for(int S=1;S<16;S++){
            ll cnt=0,ss=s;
            for(int j=1;j<=4;j++){
                if((S>>(j-1))&1){
                    cnt++;
                    ss-=c[j]*(d[j]+1);
                }
            }
            if(ss<0) continue;
            if(cnt&1) ans-=f[ss];
            else ans+=f[ss];
        }
        cout<<ans<<'\n';
    }
    return 0;
}