#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,T;
int a[maxn],f[maxn],lst[maxn],g[2005][2005];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                g[i][j]=g[i][j-1]+a[j]*a[j-1];
            }
        }
        for(int i=1;i<=n;i++){
            f[i]=f[i-1];
            if(lst[i]){
                
            }
        }
    }
}