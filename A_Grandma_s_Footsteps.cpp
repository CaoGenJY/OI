#include<bits/stdc++.h>
using namespace std;
int s,a,b,x;
int flg=0;
int main(){
    cin>>s>>a>>b>>x;
    int now=0,ans=0;
    while(true){
        if(!flg){
            if(now+a<=x){
                now+=a;
                ans+=a*s;
            }else{
                ans+=(x-now)*s;
                break;
            }
        }else{
            if(now+b<=x) now+=b;
            else break;
        }
        flg^=1;
    }
    cout<<ans;
    return 0;
}