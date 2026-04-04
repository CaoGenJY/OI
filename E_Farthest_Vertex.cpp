#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
vector<int> to[maxn];
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    
    return 0;
}