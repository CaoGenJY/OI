#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x; ans+=x-1;
    }
    cout<<ans;
    return 0;
}