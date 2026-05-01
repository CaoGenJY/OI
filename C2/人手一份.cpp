#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
signed main(){
    int n;
    cin>>n;
    int ans=1;
    while(n--){
        int x; cin>>x;
        ans=lcm(ans,x);
    }
    cout<<ans;
    return 0;
}