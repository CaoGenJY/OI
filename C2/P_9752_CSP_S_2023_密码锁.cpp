#include<bits/stdc++.h>
#define rep(i) for(int i=0;i<10;i++)
using namespace std;
int n,Mod=293834839;
int ff[10][10][10][10][10];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        for(int j=1;j<=10;j++){
            ff[(a+j)%10][b][c][d][e]++;
            ff[a][(b+j)%10][c][d][e]++;
            ff[a][b][(c+j)%10][d][e]++;
            ff[a][b][c][(d+j)%10][e]++;
            ff[a][b][c][d][(e+j)%10]++;
            ff[(a+j)%10][(b+j)%10][c][d][e]++;
            ff[a][(b+j)%10][(c+j)%10][d][e]++;
            ff[a][b][(c+j)%10][(d+j)%10][e]++;
            ff[a][b][c][(d+j)%10][(e+j)%10]++;
        }
    }
    int ans=0;
    rep(a)rep(b)rep(c)rep(d)rep(e)ans+=ff[a][b][c][d][e]==n;
    cout<<ans;
    return 0;
}