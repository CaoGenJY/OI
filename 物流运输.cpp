#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, K, e;
    if(!(cin>>n>>m>>K>>e)) return 0;
    // nodes are 1..m, A=1, B=m
    vector<vector<pair<int,int>>> adj(m+1);
    for(int i=0;i<e;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int d; cin>>d;
    // closures: each line P a b (1<P<m), closed days a..b inclusive
    vector<vector<int>> diff(m+1, vector<int>(n+3,0));
    for(int i=0;i<d;i++){
        int P,a,b; cin>>P>>a>>b;
        if(P<=1 || P>=m) continue;
        diff[P][a]++;
        diff[P][b+1]--;
    }
    // closedAny[node][day] = 1 if node closed on that day
    vector<vector<int>> closedAny(m+1, vector<int>(n+1,0));
    for(int node=1;node<=m;node++){
        int cur=0;
        for(int day=1;day<=n;day++){
            cur += diff[node][day];
            closedAny[node][day] = (cur>0) ? 1 : 0;
        }
    }
    // prefix sum of closedAny for quick union check
    vector<vector<int>> pref(m+1, vector<int>(n+1,0));
    for(int node=1;node<=m;node++){
        for(int day=1;day<=n;day++) pref[node][day] = pref[node][day-1] + closedAny[node][day];
    }

    // compute L[s][t] for 1<=s<=t<=n: shortest path length when nodes that are closed at any day in [s,t] are removed
    vector<vector<ll>> L(n+1, vector<ll>(n+1, INF));
    for(int s=1;s<=n;s++){
        for(int t=s;t<=n;t++){
            vector<char> forbidden(m+1,0);
            for(int node=2;node<=m-1;node++){
                if(pref[node][t] - pref[node][s-1] > 0) forbidden[node]=1;
            }
            // Dijkstra from 1 to m skipping forbidden nodes
            vector<ll> dist(m+1, INF);
            using pli = pair<ll,int>;
            priority_queue<pli, vector<pli>, greater<pli>> pq;
            if(!forbidden[1]){ dist[1]=0; pq.push({0,1}); }
            while(!pq.empty()){
                auto [dcur,u]=pq.top(); pq.pop();
                if(dcur!=dist[u]) continue;
                if(u==m) break;
                for(auto [v,w]: adj[u]){
                    if(forbidden[v]) continue;
                    if(dist[v] > dcur + w){
                        dist[v] = dcur + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            L[s][t] = dist[m];
        }
    }

    // DP
    vector<ll> dp(n+1, INF);
    dp[0]=0;
    for(int t=1;t<=n;t++){
        for(int s=1;s<=t;s++){
            if(L[s][t]==INF) continue;
            ll cost = dp[s-1] + L[s][t] * (t - s + 1);
            if(s>1) cost += K;
            dp[t] = min(dp[t], cost);
        }
    }

    cout<<dp[n]<<"\n";
    return 0;
}
