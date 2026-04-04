#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
long long n,s1,s2,f[maxn];
int main(){
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    f[1]=s1=1;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            f[i]=s1*i%mod;
            s2+=f[i];
        }else{
            f[i]=s2*i%mod;
            s1+=f[i];
        }
    }
    cout<<f[n]%mod;
    return 0;
}