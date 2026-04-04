#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
const double eps=1e-6;
int n;
double a[maxn][maxn];
int gauss(){
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
    if(r<n){
        for(int i=0;i<n;i++) if(fabs(a[r][i])>eps) return 2; //无解
        return 1;  //无数组解
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            a[i][n]-=a[i][j]*a[j][n];
        }
    }
    return 0;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>a[i][j];   //a[i][n]表示这个方程的右边部分
        }
    }
    int t=gauss();
    if(t==1||t==2) puts("No Solution");
    else{
        for(int i=0;i<n;i++) printf("%.2lf\n",a[i][n]);
    }
    return 0;
}