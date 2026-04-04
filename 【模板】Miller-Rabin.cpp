#include<bits/stdc++.h>
#define ll long long
using namespace std;
int primes[]={2,5,7,11,13,17,19,23,29},pc=9;
ll qmul(ll a,ll b,ll p){  //a*b%p
    ll ret=0;
    while(b){
        if(b&1) ret=(ret+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return ret;
}
ll qpow(ll a,ll k,ll p){  //a^k%p
    ll ret=1;
    while(k){
        if(k&1) ret=qmul(ret,a,p);
        a=qmul(a,a,p);
        k>>=1;
    }
    return ret;
}
bool isprime(ll x){
    ll s=0,t=x-1;  //x-1=t*2^s
    if(x==2) return true;
    if(x<2||!(x&1)) return false;
    while(!(t&1)){
        t>>=1;
        s++;
    }
    for(int i=0;i<pc&&primes[i]<x;i++){
        ll a=primes[i],b=qpow(a,t,x);
        for(int j=1;j<=s;j++){
            ll k=qmul(b,b,x);
            if(k==1&&b!=1&&b!=x-1) return false;
            b=k;
        }
        if(b!=1) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin>>T;
    while(T--){
        ll x; cin>>x;
        cout<<(isprime(x)?"Yes\n":"No\n");
    }
    cerr<<"ERR";
    return 0;
}