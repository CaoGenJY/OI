#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
string s;
ll f[maxn][5];
signed main(){
    freopen("e.in","r",stdin);
    freopen("e.out","w",stdout);
    cin>>s;
    s=" "+s;
    f[0][0]=1;
    int n=s.size()-1;
    for(int i=1;i<=n;i++){
        if(s[i]=='?'){
            for(int j=0;j<=4;j++){
                (f[i][j]+=f[i-1][j]*3)%=mod;
            }
        }else{
            for(int j=0;j<=4;j++){
                f[i][j]=f[i-1][j];
            }
        }
        if(s[i]=='?'){
            for(int j=1;j<=4;j++){
                (f[i][j]+=f[i-1][j-1])%=mod;
            }
        }else if(s[i]=='A'){
            (f[i][1]+=f[i-1][0])%mod;
        }else if(s[i]=='B'){
            (f[i][2]+=f[i-1][1])%mod;
        }else{
            (f[i][3]+=f[i-1][2])%=mod;
        }
    }
    cout<<f[n][3];
    return 0;
}