#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int p=1e9+7,maxn=405;
ll qmi(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1){
            ret*=a; ret%=p;
        }
        a*=a; a%=p;
        b>>=1;
    }
    return ret;
}
ll a[maxn][maxn*2],n; 
void out(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n*2;j++) cout<<a[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}
int Gauss_Jordan(){
    for(int i=1;i<=n;i++){   //枚举列
        int t=i;
        for(int k=i;k<=n;k++)
            if(a[k][i]){
                t=k;
                break;
            }
        if(t!=i) swap(a[t],a[i]);
        if(!a[i][i]) return 1;   //矩阵不可逆
        int inv=qmi(a[i][i],p-2);
        for(int k=1;k<=n;k++){
            if(k==i) continue;
            ll t=a[k][i]*inv%p;  //t=a[k][i]/a[i][i];
            for(int j=i;j<=2*n;j++){
                a[k][j]=((a[k][j]-a[i][j]*t%p)+p)%p;  //a[k][j]-=a[i][j]*t;
            }
        }
        for(int j=1;j<=n*2;j++){
            a[i][j]=(a[i][j]*inv)%p;  //a[i][j]/=a[i][i];
        }
    }
    return 0;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i][n+i]=1;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int ret=Gauss_Jordan();
    if(ret) puts("No Solution");
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<a[i][n+j]<<' ';
            }
            puts("");
        }
    }
    return 0;
}