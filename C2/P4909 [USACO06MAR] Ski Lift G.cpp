#include <bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,k;
int h[maxn],f[maxn];
double slope(int i,int j){     //任意两点间斜率
    return (double)(h[i]-h[j]*1.0)/(i-j);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    memset(f,0x3f,sizeof f);
    f[1]=1;
    for(int i=1;i<n;i++){
        int lst=i;
        double lstslope=-1e9;
        for(int j=i+1;j<=n&&j-i<=k;j++){
            if(slope(lst,j)>=lstslope){
                lstslope=slope(i,j);
                lst=j;
                f[j]=min(f[j],f[i]+1);
                // cout<<lst<<' '<<j<<' '<<f[j]<<'\n';
            }
        }
    }
    cout<<f[n]<<endl;
    return 0;
}