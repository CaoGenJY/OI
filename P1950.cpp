#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1005;
int n,m,top;
char a[maxn][maxn];
ll lim[maxn],l[maxn],r[maxn];
ll stk[maxn];
void monostack1(){
    top=0;
    for(int i=m;i>=1;i--){
        while(top&&lim[stk[top]]>=lim[i]){
            l[stk[top--]]=i;
        }
        stk[++top]=i;
    }
    while(top) l[stk[top--]]=0;
}
void monostack2(){
    top=0;
    for(int i=1;i<=m;i++){
        while(top&&lim[stk[top]]>lim[i]){
            r[stk[top--]]=i;
        }
        stk[++top]=i;
    }
    while(top) r[stk[top--]]=m+1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='*') lim[j]=0;
            else lim[j]++;
        }
        monostack1();
        monostack2();
        for(int i=1;i<=m;i++){
            ans+=(i-l[i])*(r[i]-i)*lim[i];
        }
        if(i==n){
            for(int i=1;i<=m;i++) cout<<lim[i]<<' ';
            puts("");
            for(int i=1;i<=m;i++) cout<<l[i]<<' ';
            puts("");
            for(int i=1;i<=m;i++) cout<<r[i]<<' ';
            puts("");
        }
    }
    cout<<ans;
    return 0;
}