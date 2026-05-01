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
void solve(){
    int j=0;
    for(int i=1;i<=la;i++){
        while(j&&b[j+1]!=a[i]) j=kmp[j];
        if(b[j+1]==a[i]) j++;
        if(j==lb){
            cout<<i-lb+1<<'\n';
            j=kmp[j];
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>a+1>>b+1;
    la=strlen(a+1),lb=strlen(b+1);
    init();
    solve();
    for(int i=1;i<=lb;i++) cout<<kmp[i]<<' ';
    puts("");
    return 0;
}