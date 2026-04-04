#include<bits/stdc++.h>
using namespace std;
int n,T,ans=0x3f3f3f3f;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>T;
    for(int i=1;i<=n;i++){
        int c,t; cin>>c>>t;
        if(t<=T){
            ans=min(ans,c);
        }
    }
    if(ans==0x3f3f3f3f) cout<<"TLE\n";
    else cout<<ans<<'\n';
    return 0;
}