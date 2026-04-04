#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m,ans;
string zidian[25];
bool f[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>zidian[i];
    while(m--){
        memset(f,false,sizeof f); f[0]=1;
        string s; cin>>s; ans=0;
        for(int i=0;i<(int)s.size();i++){
            for(int j=1;j<=n;j++){
                int len=zidian[j].size();
                if(len-1>i) continue;
                bool flg=true;
                for(int k=0;k<len;k++){
                    if(s[i-k]!=zidian[j][len-k-1]){
                        flg=false;
                        break;
                    }
                }
                if(flg&&(i-len==-1||f[i-len])){
                    f[i]=1,ans=i+1;
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}