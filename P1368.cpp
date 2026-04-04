#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+7;
int n;
int a[maxn];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int i=0,j=1,k=0;
    while(i<n&&j<n&&k<n){
        int t=a[(i+k)%n]-a[(j+k)%n];
        if(t==0) k++;
        else{
            if(t>0) i+=k+1;
            else j+=k+1;
            if(i==j) ++j;
            k=0;
        }
    }
    for(int u=0;u<n;u++) cout<<a[(min(i,j)+u)%n]<<' ';
    return 0;
}