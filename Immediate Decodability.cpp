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
int cs;
int main(){
    while(true){
        ++cs;
        flg=false;
        for(int i=0;i<maxn;i++){
		    ed[i]=0;
			for(int j=0;j<=64;j++){
				tree[i][j]=0;
			}
		}
        idx=0; int cnt=0;
        while(cin>>ch){
            cnt++;
            if(ch[0]=='9'&&strlen(ch)==1) break;
            else insert(ch);
        }
        if(!cnt) return 0;
        if(flg) cout<<"Set "<<cs<<" is not immediately decodable\n";
        else cout<<"Set "<<cs<<" is immediately decodable\n";
    }
    return 0;
}