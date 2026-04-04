#include<bits/stdc++.h>
using namespace std;
const int maxn=2000010;
int n,m,idx;
int tree[maxn][65],cnt[maxn],cnt2[maxn];
int getnum(char ch){
    if(ch>='A'&&ch<='Z') return ch-'A';
    else if(ch>='a'&&ch<='z') return ch-'a'+26;
    return ch-'0'+52;
}
void insert(char ch[]){
    int p=0,len=strlen(ch);
    for(int i=0;i<len;i++){
        int now=getnum(ch[i]);
        if(!tree[p][now]) tree[p][now]=++idx;
        p=tree[p][now];
    }
    cnt2[p]++;
}
int find(char ch[]){
    int p=0,len=strlen(ch);
    for(int i=0;i<len;i++){
        int now=getnum(ch[i]);
        if(!tree[p][now]) return -1;
        p=tree[p][now];
    }
    if(!cnt2[p]) return -1;
    if(cnt[p]) return -2;
    cnt[p]++;
    return 0;
}
char tmp[maxn];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("0in.in","r",stdin);
    #endif
    cin>>n;
    while(n--){
        cin>>tmp;
        insert(tmp);
    }
    cin>>m;
    while(m--){
        cin>>tmp;
        int ret=find(tmp);
        if(ret==-1) puts("WRONG");
        else if(ret==-2) puts("REPEAT");
        else{
            puts("OK");
        }
    }
    return 0;
}