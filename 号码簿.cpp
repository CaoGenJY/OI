#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,maxT=65;
int idx;
int tree[maxn][maxT];
bool ed[maxn],flg=false;
char ch[maxn];
int getnum(char c){
	if(c>='A'&&c<='Z') return c-'A';
	else if(c>='a'&&c<='z') return c-'a'+26;
	return c-'0'+52;
}
void insert(char *ch){
    int len=strlen(ch),p=0,fflg=false,ffflg=false;
    for(int i=0;i<len;i++){
        int now=getnum(ch[i]);
        if(!tree[p][now]) tree[p][now]=++idx,fflg=true;
        if(ed[p]) ffflg=true;
        p=tree[p][now];
    }
    if(!fflg||ffflg) flg=true;
    ed[p]=true;
}
int T,n;
int main(){
    cin>>T;
    while(T--){
        flg=false;
        for(int i=0;i<maxn;i++){
		    ed[i]=0;
			for(int j=0;j<=64;j++){
				tree[i][j]=0;
			}
		}
        idx=0;
        cin>>n;
        while(n--){
            cin>>ch;
            insert(ch);
        }
        if(flg) puts("NO");
        else puts("YES");
    }
    return 0;
}