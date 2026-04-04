#include<bits/stdc++.h>
using namespace std;
const int MAXD = 15;
int p[MAXD];
long long c[MAXD];

int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int D; long long G;
    if(!(cin>>D>>G)) return 0;
    for(int i=1;i<=D;i++) cin>>p[i]>>c[i];

    int ans = INT_MAX;
    int lim = 1<<D;
    for(int mask=0; mask<lim; mask++){
        long long score=0;
        int cnt=0;
        for(int i=1;i<=D;i++){
            if(mask&(1<<(i-1))){
                score+=100LL*i*p[i]+c[i];
                cnt+=p[i];
            }
        }
        if(score>=G){ans=min(ans, cnt);continue;}
        for(int i=D;i>=1;i--){
            if(mask&(1<<(i-1))) continue;
            long long val=100LL*i;
            int can=p[i]-1;
            if(can<=0) continue;
            long long ne=(G-score+val-1)/val;
            long long t=min<long long>(can,ne);
            score+=t*val;
            cnt+=(int)t;
            if(score >= G) break;
        }
        if(score >= G) ans = min(ans, cnt);
    }

    cout<<ans<<"\n";
    return 0;
}