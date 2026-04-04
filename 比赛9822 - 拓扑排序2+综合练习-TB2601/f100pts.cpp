#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=1e8;
struct FHQ_Treap{
    int rt,idx,timer;
    struct node{
        int l,r;
        int siz,val,key;
        int id;  //insert time
        string uid;
    }tr[maxn];
    int newnode(int k,string uid){
        tr[++idx].key=k; tr[idx].val=rand();
        tr[idx].siz=1; tr[idx].l=tr[idx].r=0;
        tr[idx].id=++timer; tr[idx].uid=uid;
        return idx;
    }
    void pushup(int p){
        tr[p].siz=tr[tr[p].l].siz+tr[tr[p].r].siz+1;
    }
    void split(int p,int k,int id,int &x,int &y){
        if(!p) x=y=0;
        else{
            if(tr[p].key<k||(tr[p].key==k&&tr[p].id>=id)){
                x=p;
                split(tr[p].r,k,id,tr[p].r,y);
            }else{
                y=p;
                split(tr[p].l,k,id,x,tr[p].l);
            }
            pushup(p);
        }
    }
    int merge(int x,int y){
        if(!x||!y) return x+y;
        if(tr[x].val>tr[y].val){
            tr[x].r=merge(tr[x].r,y);
            pushup(x);
            return x;
        }else{
            tr[y].l=merge(x,tr[y].l);
            pushup(y);
            return y;
        }
    }
    int x,y,z;
    void insert(int k,string uid){
        int u=newnode(k,uid);
        split(rt,k,tr[u].id,x,y);
        rt=merge(merge(x,u),y);
    }
    void del(int k,int id){
        split(rt,k,id,x,z); split(x,k,id+1,x,y);
        y=merge(tr[y].l,tr[y].r);
        rt=merge(merge(x,y),z);
    }
    int get_rank(int k,int id){
        split(rt,k,id,x,y);
        int ret=tr[y].siz+1;
        merge(x,y);
        return ret;
    }
    string get_uid(int rank){
        int now=rt;
        while(now){
            if(tr[tr[now].r].siz+1==rank){
                break;
            }else if(tr[tr[now].r].siz>=rank){
                now=tr[now].r;
            }else{
                rank-=tr[tr[now].r].siz+1;
                now=tr[now].l;
            }
        }
        return tr[now].uid;
    }
}bt;
int string_to_int(string s){
    int ret=0;
    for(int i=0;i<(int)s.size();i++){
        ret=ret*10+s[i]-'0';
    }
    return ret;
}
int n,pnum;
map<string,pair<int,int> > V;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char op; string s; int v;
        cin>>op>>s;
        if(op=='+'){
            cin>>v;
            if(V.count(s)){
                bt.del(V[s].first,V[s].second);
            }else pnum++;
            bt.insert(v,s);
            V[s].first=v;
            V[s].second=bt.timer;
        }else{
            if(s[0]>='0'&&s[0]<='9'){
                int rk=string_to_int(s);
                for(int i=0;i<10&&rk+i<=pnum;i++){
                    cout<<bt.get_uid(rk+i)<<' ';
                }
                cout<<'\n';
            }else{
                cout<<bt.get_rank(V[s].first,V[s].second)<<'\n';
            }
        }
    }
    return 0;
}
