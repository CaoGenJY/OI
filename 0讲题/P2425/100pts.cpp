#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int tmp[1000005];
bool check(ll x,ll p){
    int len=0;
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
        if(x==1||x==2){
            cout<<2<<'\n';
            continue;
        }
        bool flg=false;
        for(ll i=2;i*i<=x;i++){
            if(check(x,i)){
                cout<<i<<'\n';
                flg=true;
                break;
            }
        }
        if(!flg){
            ll i;
            ll sqt=(ll)sqrt((double)x);
            for(i=sqt;i>=1;i--){
                if(x%i==0){
                    flg=true;
                    break;
                }
            }
            cout<<x/i-1<<'\n';
        }
    }
    return 0;
}