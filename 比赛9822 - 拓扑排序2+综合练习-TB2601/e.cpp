#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+4;
int n,Q,maxx=1;
int a[maxn],f[maxn];
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=1;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i]){
                f[i]=max(f[i],f[j]+1);
                maxx=max(maxx,f[i]);
            }
        }
    }
    cin>>Q;
    while(Q--){
        int len; cin>>len;
        if(len>maxx) cout<<"Impossible\n";
        else{
            int lst=-1;
            for(int i=1;i<=n;i++){
                if(f[i]>=len&&a[i]>lst){
                    lst=a[i];
                    cout<<a[i]<<' ';
                    len--;
                    if(len==0) break;
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}