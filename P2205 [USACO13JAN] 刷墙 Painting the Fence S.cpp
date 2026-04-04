    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    #include<cstring>
    #include<ctime>
    #include<set>
    #define ll long long
    using namespace std;
    const int maxn=2e5+5;
    struct node{
        int pos,type;
        bool operator <(const node &y) const{
            if(pos!=y.pos) return pos<y.pos;
            return type<y.type;
        }
    };
    multiset<node> st;
    int n,k,now=0,nk=0,lst=0;
    ll ans=0;
    void solve(){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            char dir; int dis; cin>>dis>>dir;
            if(dir=='L'){
                st.insert({now-dis,0});
                st.insert({now,1});
                now-=dis;
            }else{
                st.insert({now,0});
                st.insert({now+dis,1});
                now+=dis;
            }
        }
        int lst=0;
        for(set<node>::iterator it=st.begin();it!=st.end();it++){
            int pos=(*it).pos,type=(*it).type;
            if(nk>=k){
                ans+=abs(pos-lst);
            }
            if(type==0) nk++;
            else nk--;
            lst=pos;
        }
        cout<<ans;
    }
    int main(){
        ios::sync_with_stdio(false); cin.tie(0);
        #ifndef ONLINE_JUDGE
        freopen("in.in","r",stdin);
        freopen("out.out","w",stdout);
        #endif
        int T=1; //cin>>T;
        for(int i=1;i<=T;i++){
            solve();
        }
        #ifndef ONLINE_JUDGE
        cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000.0<<"ms\n";
        #endif
        return 0;
    }