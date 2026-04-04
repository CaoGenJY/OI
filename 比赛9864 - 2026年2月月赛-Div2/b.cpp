#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,m,k,r;
char tmp[maxn][maxn],ch[maxn][maxn];
void out(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<ch[i][j];
        }
        cout<<'\n';
    }
}
void rotate(){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            ch[j][n-i+1]=tmp[i][j];
        }
    }
    swap(n,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            tmp[i][j]=ch[i][j];
        }
    }
}
int main(){
    freopen("scalerotate.in","r",stdin);
    freopen("scalerotate.out","w",stdout);
    cin>>r>>k>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>tmp[i][j];
        }
    }
    if(r>=90) rotate();
    if(r>=180) rotate();
    if(r>=270) rotate();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int ii=1;ii<=k;ii++){
                for(int jj=1;jj<=k;jj++){
                    ch[ii+(i-1)*k][jj+(j-1)*k]=tmp[i][j];
                }
            }
        }
    }
    n*=k; m*=k;
    out();
    return 0;
}