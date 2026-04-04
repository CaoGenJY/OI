#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+6;
struct Aho_Corasick{
	static const int ALPHA=26;
	struct Trie{
		int end,fail,last;
		int ch[ALPHA];
	}tr[maxn];
	int idx=0;
	void insert(string s){
		int p=0;
		for(int i=0;i<(int)s.size();i++){
			int now=s[i]-'a';
			if(!tr[p].ch[now]){
				tr[p].ch[now]=++idx;
			}
			p=tr[p].ch[now];
		}
		tr[p].end++;
	}
	void build_fail(){
		queue<int> q;
		for(int i=0;i<ALPHA;i++){
			if(tr[0].ch[i]){
				tr[tr[0].ch[i]].fail=0;
				tr[tr[0].ch[i]].last=0;
				q.push(tr[0].ch[i]);
			}
		}
		while (!q.empty()) {
	        int u=q.front(); q.pop();
	        for (int i=0;i<ALPHA;i++) {
	            int &v=tr[u].ch[i];
	            int f=tr[tr[u].fail].ch[i];
	            if(v){
	                tr[v].fail=f;
	                tr[v].last=(tr[f].end?f:tr[f].last);
	                q.push(v);
	            }else{
	                v=f;
	            }
	        }
	        if(u==0) tr[u].fail=tr[u].last=0;
	    }
	}
	int find(string s){
		int ret=0,p=0;
		for(int i=0;i<(int)s.size();i++){
			int now=s[i]-'a';
			p=tr[p].ch[now];
			for(int tmp=p;tmp&&tr[tmp].end>=0;tmp=tr[tmp].last){
				ret+=tr[tmp].end; tr[tmp].end=-1;
			}
		}
		return ret;
	}
}ac;
void solve(){
    int n; string s;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>s;
    	ac.insert(s);
    }
    ac.build_fail();
    cin>>s;
    cout<<ac.find(s)<<'\n';
    return;
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