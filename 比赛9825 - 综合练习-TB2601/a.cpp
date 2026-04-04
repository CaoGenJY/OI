#include<bits/stdc++.h>
using namespace std;
int n,ansid;
double T,A,ans=1e9;
double dis(double x,double y){
    return fabs(x-y);
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>n>>T>>A;
    for(int i=1;i<=n;i++){
        double h; cin>>h;
        if(dis(T-h*0.006,A)<ans){
            ansid=i;
            ans=dis(T-h*0.006,A);
        }
    }
    cout<<ansid;
    return 0;
}