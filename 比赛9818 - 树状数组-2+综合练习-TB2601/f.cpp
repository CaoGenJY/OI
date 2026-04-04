#include<bits/stdc++.h>
using namespace std;
const int maxn=400;
int num[maxn];
string chg[maxn][maxn],s;
map<char,int> ys;
bool f[205][205][10];
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>num[1]>>num[2]>>num[3]>>num[4];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=num[i];j++){
            cin>>chg[i][j];
        }
    }
    ys['W']=1; ys['I']=2; ys['N']=3; ys['G']=4;
    cin>>s;
    int n=s.size();
    for(int len=1;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(i==j){
                f[i][j][ys[s[i]]]=true;
            }else if(len==2){
                string tmp=s.substr(i,2); 
                for(int k=1;k<=4;k++){
                    for(int u=1;u<=num[k];u++){
                        if(tmp==chg[k][u]) f[i][j][k]=true;
                    }
                }
            }else{
                for(int k=1;k<=4;k++){  //i~j -> k
                    bool flg=false;
                    for(int u=1;u<=num[k];u++){
                        if(flg) break;
                        int k1=ys[chg[k][u][0]],k2=ys[chg[k][u][1]];
                        for(int fg=i;fg<j;fg++){
                            if(f[i][fg][k1]&&f[fg+1][j][k2]){
                                f[i][j][k]=1;
                                flg=true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    bool flg=true;
    if(f[0][n-1][1]) cout<<'W',flg=false;
    if(f[0][n-1][2]) cout<<'I',flg=false;
    if(f[0][n-1][3]) cout<<'N',flg=false;
    if(f[0][n-1][4]) cout<<'G',flg=false;
    if(flg) puts("The name is wrong!");
    return 0;
}