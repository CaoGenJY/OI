#include<bits/stdc++.h>
using namespace std;
int a[5],ans=0x3f3f3f3f;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin>>a[1]>>a[2]>>a[3];
    do{
        ans=min(ans,abs(a[2]-a[1])+abs(a[3]-a[2]));
    }while(next_permutation(a+1,a+4));
    cout<<ans;
    return 0;
}