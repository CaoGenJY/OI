#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+6;
int la,lb;
char a[maxn],b[maxn];
int kmp[maxn];
void init(){
    int j=0;
    for(int i=2;i<=lb;i++){
        while(j&&b[i]!=b[j+1]) j=kmp[j];
        if(b[j+1]==b[i]) j++;
        kmp[i]=j;
    }
}
int solve(){
    int j=0,ans=0;
    for(int i=1;i<=la;i++){
        while(j&&b[j+1]!=a[i]) j=kmp[j];
        if(b[j+1]==a[i]) j++;
        if(j==lb){
            ans++;
            j=0;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(true){
        cin>>a+1;
        if(a[1]=='#') break;
        cin>>b+1;
        la=strlen(a+1),lb=strlen(b+1);
        memset(kmp,0,sizeof kmp);
        init();
        cout<<solve()<<'\n';
    }
    return 0;
}