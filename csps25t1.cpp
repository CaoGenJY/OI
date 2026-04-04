#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n;
struct node{
    int a,b,c;
}p[maxn];
vector<int> t[4];
pair<int,int> fi(int a,int b,int c){
    int maxx=0,nxt=0;
    if(a>maxx) maxx=a;
    else if(a>nxt) nxt=a;
    if(b>maxx) maxx=b;
    else if(b>nxt) nxt=b;
    if(c>maxx) maxx=c;
    else if(c>nxt) nxt=c;
    return make_pair(maxx,nxt);
}
bool cmp(node x,node y){
    pair<int,int> xx=fi(x.a,x.b,x.c);
    pair<int,int> yy=fi(y.a,y.b,y.c);
    return xx.first-xx.second<yy.first-yy.second;
}
int main(){
    // freopen("club.in","r",stdin);
    // freopen("club.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>T;
    while(T--){
        int ans=0;
        t[1].clear(); t[2].clear(); t[3].clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i].a>>p[i].b>>p[i].c;
            if(p[i].a>=p[i].b&&p[i].a>=p[i].c) {t[1].push_back(i); ans+=p[i].a;}
            else if(p[i].b>=p[i].a&&p[i].b>=p[i].c) {t[2].push_back(i); ans+=p[i].b;}
            else {t[3].push_back(i); ans+=p[i].c;}
        }
        for(int i=1;i<=3;i++){
            if(t[i].size()>n/2){
                sort(t[i].begin(),t[i].end(),cmp);
                for(const auto it:t[i]){
                    pair<int,int> tmp=fi(p[it].a,p[it].b,p[it].c);
                    ans-=tmp.first-tmp.second;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}