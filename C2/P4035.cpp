#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
const double eps=1e-6;
int n;
double a[maxn][maxn],A[maxn][maxn];
void gauss(){
    int r,c;   //r->当前行数 c->当前列数
    for(r=0,c=0;c<n;c++){
        //找主元
        int t=r;
        for(int i=r;i<n;i++){
            if(fabs(a[i][c])>fabs(a[t][c])){
                t=i;
            }
        }
        if(fabs(a[t][c])<eps) continue;
        //交换
        for(int i=c;i<=n;i++) swap(a[r][i],a[t][i]);
        //归一
        for(int i=n;i>=c;i--) a[r][i]/=a[r][c];
        //消元
        for(int i=r+1;i<n;i++){
            if(fabs(a[i][c])<eps) continue;
            for(int j=n;j>=c;j--){
                a[i][j]-=a[i][c]*a[r][j];
            }
        }
        r++;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            a[i][n]-=a[i][j]*a[j][n];
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>A[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i-1][j-1]+=2*(A[i][j]-A[0][j]);
            a[i-1][n]+=A[i][j]*A[i][j]-A[0][j]*A[0][j];
        }
    }
    gauss();
    for(int i=0;i<n;i++){
        printf("%.3lf ",a[i][n]);
    }
    return 0;
}