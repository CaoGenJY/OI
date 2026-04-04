#include<iostream>
#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iomanip>
using namespace std;
const int maxn=1005;
double n,s;
double f[maxn][maxn];
void solve(){
    cin>>n>>s;
    f[(int)n][(int)s]=0;
    for(int i=n;i>=0;i--){
        for(int j=s;j>=0;j--){
            if(i==n&&j==s) continue;
            f[i][j]=
            ((n-i)*(s-j)/(n*s)*f[i+1][j+1]+
            (n-i)*j/(n*s)*f[i+1][j]+
            i*(s-j)/(n*s)*f[i][j+1]+1)
            /(1-i*j/(n*s));
        }
    }
    cout<<fixed<<setprecision(4)<<f[0][0]<<'\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    int T=1; //cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000.0<<"ms\n";
    #endif
    return 0;
}