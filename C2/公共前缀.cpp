#include<bits/stdc++.h>
using namespace std;
const int maxn=20005,maxl=505;
int idx;
int tree[maxl][65],cnt[maxn];
char tmp[maxl];
int getnum(char c){
	if(c>='A'&&c<='Z') return c-'A';
	else if(c>='a'&&c<='z') return c-'a'+26;
	return c-'0'+52;
}
void insert(char ch[]){
	int p=0,len=strlen(ch);
	for(int i=0;i<len;i++){
		int now=getnum(ch[i]);
		if(!tree[p][now]){
			tree[p][now]=++idx;
		}
		cnt[tree[p][now]]++;
		p=tree[p][now];
	}
}
int find(char ch[]){
	int p=0,len=strlen(ch);
    int i=0,flg=0;
	for(;i<len;i++){
		int now=getnum(ch[i]);
		if(!tree[p][now]) break;
        flg=1;
		p=tree[p][now];
	}
    if(!flg) return 0;
	return i+1;
}
char s[maxn][maxl];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        insert(s[i]);
    }
    for(int i=1;i<=n;i++){
        
    }
	return 0;
}