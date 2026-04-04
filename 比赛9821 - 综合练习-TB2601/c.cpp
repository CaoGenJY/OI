#include<bits/stdc++.h>
using namespace std;
string s;
long long k;
int main(){
    // freopen("c.in","r",stdin);
    // freopen("c.out","w",stdout);
    cin>>s>>k;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='1'){
            k--;
            if(k==0){
                cout<<"1\n";
                return 0;
            }
        }else{
            cout<<s[i]<<'\n';
            return 0;
        }
    }
    return 0;
}