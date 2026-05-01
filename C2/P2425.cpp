#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1500000;
bool is[10000007];
int n;
int len,tmp[maxn];
bool check(ll x,ll p){
    len=0;
    while(x){
        tmp[++len]=x%p;
        x/=p;
    }
    for(int i=1;i<=len/2;i++){
        if(tmp[i]!=tmp[len-i+1]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    while(n--){
        ll x;
        cin>>x;
        for(int i=2;;i++){
            if(check(x,i)){
                cout<<i<<'\n';
                break;
            }
        }
    }
    return 0;
}