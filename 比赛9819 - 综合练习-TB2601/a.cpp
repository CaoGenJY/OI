#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
char ch[maxn];
int ans=0;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>ch+1; int n=strlen(ch+1);
    if((ch[2]>='A'&&ch[2]<='Z')||(ch[n]>='A'&&ch[n]<='Z')){
        puts("WA");
        return 0;
    }
    for(int i=3;i<=n-1;i++){
        if(ch[i]=='C') ans++;
        else if(ch[i]<='Z'&&ch[i]>='A'){
            puts("WA");
            return 0;
        }
    }
    if(ans==1&&ch[1]=='A') puts("AC");
    else puts("WA");
    return 0;
}