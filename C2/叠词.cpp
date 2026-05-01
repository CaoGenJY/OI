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
    freopen("power11.in","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    while(true){
        cin>>b+1;
        if(b[1]=='.') break;
        lb=strlen(b+1);
        memset(kmp,0,sizeof kmp);
        init();
        // if(!kmp[lb]||lb%(lb-kmp[lb])!=0) puts("1");
        /*else*/ cout<<lb/(lb-kmp[lb])<<'\n';
    }
    return 0;
}