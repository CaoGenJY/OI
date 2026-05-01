#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+7;
int n;
char ch[maxn];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>ch;
    int i=0,j=1,k=0;
    while(i<n&&j<n&&k<n){
        int t=ch[(i+k)%n]-ch[(j+k)%n];
        if(t==0) k++;
        else{
            if(t>0) i+=k+1;
            else j+=k+1;
            if(i==j) ++j;
            k=0;
        }
    }
    for(int u=0;u<n;u++) cout<<ch[(min(i,j)+u)%n];
    return 0;
}