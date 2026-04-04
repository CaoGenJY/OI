#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=105,P=131;
string s;
bool dfs(int i){
    bool ret=false;
    if(i==s.size()) return true;
    if(i+3<(int)s.size()&&s[i]=='w'&&s[i+1]=='o'&&s[i+2]=='r'&&s[i+3]=='k'){
        ret|=dfs(i+4);
    }
    if(i+5<(int)s.size()&&s[i]=='w'&&s[i+1]=='o'&&s[i+2]=='r'&&s[i+3]=='k'&&s[i+4]=='e'&&s[i+5]=='r'){
        ret|=dfs(i+6);
    }
    if(i+4<(int)s.size()&&s[i]=='e'&&s[i+1]=='r'&&s[i+2]=='a'&&s[i+3]=='s'&&s[i+4]=='e'){
        ret|=dfs(i+5);
    }
    if(i+5<(int)s.size()&&s[i]=='e'&&s[i+1]=='r'&&s[i+2]=='a'&&s[i+3]=='s'&&s[i+4]=='e'&&s[i+5]=='r'){
        ret|=dfs(i+6);
    }
    return ret;
}
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin>>s;
    int ans=dfs(0);
    if(ans) puts("YES");
    else puts("NO");
    return 0;
}