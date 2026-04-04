#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
using ll=long long;
int n, phi[N], primes[N];
ll phisum[N];
bool vis[N]={0};
void euler() {
    for (int i=2;i<=N-5;++i) phi[i] = i;
    for (int i=2;i<=N-5;++i) {
        if(!vis[i]) primes[++primes[0]]=i,phi[i]=i-1;
        for(int j=1;j<=primes[0];j++){
            if(i*primes[j]>N-6) break;
            vis[i*primes[j]]=1;
            if(i%primes[j]==0){
                phi[i*primes[j]]=phi[i]*primes[j];
                break;
            }else phi[i*primes[j]]=phi[i]*(primes[j]-1);
        }
    }
    for(int i=1;i<=N-5;i++) phisum[i]=phisum[i-1]+phi[i];
}
int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    euler();
    while(true){
        int x;
        cin>>x;
        if(x==0) break;
        cout<<phisum[x]<<'\n';
    }
    return 0;
}