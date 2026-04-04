#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
vector<string> v;
map<string,int> mp;
int main(){
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n-k+1;i++){
        string now=s.substr(i,k);
        if(!mp.count(now)){
            v.push_back(now);
            mp[now]=0;
        }
        mp[now]++;
    }
    sort(v.begin(),v.end());
    int x=0;
    for(const string &it:v) x=max(x,mp[it]);
    cout<<x<<'\n';
    for(const string &it:v){
        if(mp[it]==x) cout<<it<<' ';
    }
    return 0;
}