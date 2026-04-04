#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("ngs.in","r",stdin);
    freopen("ngs.out","w",stdout);
    double a,b,c;
    while(cin>>a>>b>>c){
        double r=(b-c)/(a-b),d=b-a*r;
        cout<<r*c+d<<endl;
    }
    return 0;
}
