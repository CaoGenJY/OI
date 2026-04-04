#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,la,lb,ra,rb;
int a[maxn],b[maxn];
int getans(){
    int ans=0; la=lb=1; ra=rb=n;
    while(la<=ra&&lb<=rb){
        while(la<=ra&&lb<=rb&&a[la]>b[lb]){
            ans+=2;
            la++;
            lb++;
        }
        while(la<=ra&&lb<=rb&&a[ra]>b[rb]){
            ans+=2;
            ra--;
            rb--;
        }
        if(la<=ra&&lb<=rb){
            if(a[ra]==b[lb]) ans++;
            ra--;
            lb++;
        }
    }
    return ans;
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+n+1,greater<int>());
    sort(b+1,b+n+1,greater<int>());
    cout<<getans()<<' ';
    for(int i=1;i<=n;i++) swap(a[i],b[i]);
    sort(a+1,a+n+1,greater<int>());
    sort(b+1,b+n+1,greater<int>());
    cout<<n*2-getans()<<'\n';
    return 0;
}
