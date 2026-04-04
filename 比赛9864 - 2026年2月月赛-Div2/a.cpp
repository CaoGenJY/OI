#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
char ch[maxn];
int main(){
    freopen("ab.in","r",stdin);
    freopen("ab.out","w",stdout);
    cin>>ch+1;
    int n=strlen(ch+1),cnt=0,ans=0;
    for(int i=1;i<=n;i++){
        if(ch[i]=='A'){
            ans+=i-(cnt+1);
            cnt++;
        }
    }
    cout<<ans;
    return 0;
}