#include<bits/stdc++.h>
using namespace std;
const int maxn=2.2e7;
int cnt;
int p[maxn];
char ch[maxn],s[maxn];
void build(){
    int len=strlen(ch);
    s[++cnt]='~'; s[++cnt]='#';
    for(int i=0;i<len;i++){
        s[++cnt]=ch[i];
        s[++cnt]='#';
    }
    s[++cnt]='!';
}
int manacher(){
    int len=strlen(s);
    int ret=0,mr=0,mid=0;
    for(int i=2;i<cnt;i++){
        if(i<=mr) p[i]=min(p[mid*2-i],mr-i+1);
        else p[i]=1;
        while(s[i-p[i]]==s[i+p[i]]) p[i]++;
        if(i+p[i]>mr) mr=i+p[i]-1,mid=i;
        ret=max(ret,p[i]);
    }
    return ret-1;
}
int main(){
    cin>>ch;
    build();
    cout<<manacher();
    return 0;
}