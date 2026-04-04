#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int A,B,n;
double ma[maxn][maxn],dp[maxn][maxn][maxn][maxn][maxn],ave;
bool vis[maxn][maxn][maxn][maxn][maxn];

double DP(int a,int b,int x,int y,int num){
    if(vis[a][b][x][y][num]){
        return dp[a][b][x][y][num];
    }
    vis[a][b][x][y][num]=1;
    double ret=0x3f3f3f3f;
    if(num==1){
        ret=0;
        for(int i=a;i<=x;i++){
            for(int j=b;j<=y;j++){
                ret+=ma[i][j];
            }
        }
        ret-=ave;
        ret*=ret;
        return dp[a][b][x][y][num]=ret;
    }
    for(int i=b;i<y;i++){
        for(int k=1;k<num;k++){
            ret=min(ret,DP(a,b,x,i,k)+DP(a,i+1,x,y,num-k));
        }
    }
    for(int i=a;i<x;i++){
        for(int k=1;k<num;k++){
            ret=min(ret,DP(a,b,i,y,k)+DP(i+1,b,x,y,num-k));
        }
    }
    return dp[a][b][x][y][num]=ret;
}

int main(){
    cin>>A>>B>>n;
    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            cin>>ma[i][j];
            ave+=ma[i][j];
        }
    }
    ave/=double(n);
    cout<<fixed<<setprecision(2)<<sqrt(DP(1,1,A,B,n)/n);
    return 0;
}