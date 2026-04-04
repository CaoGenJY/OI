#include <bits/stdc++.h>
namespace nms {
    const int N = 1e6+6;
    int n, phi[N], primes[N], phisum[N];
    bool vis[N]={0};
    void euler() {
        for (int i = 2; i <= N - 5; ++i) phi[i] = i;
        for (int i = 2; i <= N - 5; ++i) {
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
    void solve(int cs) {
        if (n == 1) {
            puts("0");
            exit(0);
        }
        int ans = phisum[n-1]-phisum[1];
        std::cout<<cs<<' '<<n-1<<' '<<ans*2+3<<'\n';
    }
}
using namespace nms;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    euler();
    int T;
    std::cin>>T;
    for(int i=1;i<=T;i++){
        std::cin>>n;
        n++;
        solve(i);
    }
    return 0;
}