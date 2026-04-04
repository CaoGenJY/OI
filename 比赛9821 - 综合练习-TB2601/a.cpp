#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i*4<=n;i++){
        if((n-i*4)%7==0){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}