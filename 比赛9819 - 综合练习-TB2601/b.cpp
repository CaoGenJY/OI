#include<bits/stdc++.h>
using namespace std;
string x,y;
int n;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin>>x>>y;
    n=x.size();
    for(int i=0;i<n;i++){
        if(x.substr(n-i,i)+x.substr(0,n-i)==y){
            cout<<i<<'\n';
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}