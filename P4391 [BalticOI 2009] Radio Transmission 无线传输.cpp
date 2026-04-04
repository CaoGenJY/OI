#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+6;
int lb;
char b[maxn];
int kmp[maxn];
void init(){
    int j=0;
    for(int i=2;i<=lb;i++){
        while(j&&b[i]!=b[j+1]) j=kmp[j];
        if(b[j+1]==b[i]) j++;
        kmp[i]=j;
    }
}
int main(){
    // freopen("/home/caogenjy/下载/jiangyu_1426525_power10/power10.in","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>lb>>b+1;
    // if(b[1]=='.') break;
    init();
    // if(!kmp[lb]||lb%(lb-kmp[lb])!=0) puts("1");
    /*else*/ cout<<lb-kmp[lb]<<'\n';
    return 0;
}