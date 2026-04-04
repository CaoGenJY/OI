#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
ll n,trans;
ll p1[maxn],p2[maxn];
ll f[maxn][5]; //1-->Beijing 2-->Tianjin
int main(){
    freopen("work.in","r",stdin);
    freopen("work.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>trans;
    for(int i=1;i<=n;i++) cin>>p1[i]>>p2[i];
    f[1][1]=p1[1]; f[1][2]=p2[1]-trans;
    for(int i=2;i<=n;i++){
        f[i][1]=max(f[i-1][1],f[i-1][2]-trans)+p1[i];
        f[i][2]=max(f[i-1][2],f[i-1][1]-trans)+p2[i];
    }
    cout<<max(f[n][1],f[n][2]);
    return 0;
}