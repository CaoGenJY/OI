#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+6;
int a[maxn];
int main(){
    freopen("6.out","r",stdin);
    for(int i=1;i<=100000;i++) cin>>a[i];
    freopen("6.my","r",stdin);
    for(int i=1;i<=100000;i++){
        int x; cin>>x;
        // if(x!=a[i]){
        //     cout<<i<<' '<<a[i]<<' '<<x<<endl;
        //     return 0;
        // }
    }
    puts("None");
    return 0;
}