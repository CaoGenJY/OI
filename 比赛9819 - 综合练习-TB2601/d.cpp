#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
struct node{
    int l,r;
}a[maxn];
bool cmp(node x,node y){
    return x.r<y.r;
}
int main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i].l>>a[i].r;
    for(int i=1;i<=m;i++) a[i].r = a[i].r - 1;
    sort(a+1,a+m+1,cmp);
    int ans = 0;
    int last = 0; 
    for(int i=1;i<=m;i++){
        if(a[i].l>last){
            ans++;
            last=a[i].r;
        }
    }
    cout<<ans;
    return 0;
}