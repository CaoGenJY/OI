#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,maxx=0,minn=0x3f3f3f3f,a[maxn];
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]),minn=min(minn,a[i]);
    cout<<maxx-minn;
    return 0;
}