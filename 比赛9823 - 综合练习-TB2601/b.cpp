#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e2+2;
int n;
struct node{
    ll x,y,h;
}a[maxn];
bool cmp(node x,node y){return x.h>y.h;}
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].h;
    sort(a+1,a+n+1,cmp);
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            ll H=llabs(a[1].x-i)+llabs(a[1].y-j)+a[1].h,flg=1;
            for(int k=2;k<=n;k++){
                ll mht=llabs(a[k].x-i)+llabs(a[k].y-j);
                ll hh=max(H-mht,0LL);
                if(hh!=a[k].h){
                    flg=0;
                    break;
                }
            }
            if(flg){
                cout<<i<<' '<<j<<' '<<H<<'\n';
                return 0;
            }
        }
    }
    return 0;
}
