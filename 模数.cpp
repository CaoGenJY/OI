#include<bits/stdc++.h>
using namespace std;
const int eps=1e-6;
int n;
bool isprime(int x){
    if(x<=1) return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    int T; cin>>T;
    while(T--){
        cin>>n;
        if(n==4) puts("2");
        else if(isprime(n)){
            cout<<n-1<<'\n';
        }else puts("0");        
    }
    return 0;
}