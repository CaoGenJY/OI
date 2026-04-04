#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll qmi(ll a,ll k,ll p){  //a^k%p
    ll ret=1;
    while(k){
        if(k&1) ret=ret*a%p;
        a=a*a%p;
        k>>=1;
    }
    return ret;
}
int main(){
    ll n,m,k,x; cin>>n>>m>>k>>x;
    cout<<(x%n+m*qmi(10,k,n)%n)%n;
}