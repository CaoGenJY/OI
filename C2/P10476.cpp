#include<bits/stdc++.h>
using namespace std;
int solve(char *ch){
    int len=strlen(ch);
    int i=0,j=1,k=0;
    while(i<len&&j<len&&k<len){
        int t=ch[(i+k)%len]-ch[(j+k)%len];
        if(t==0) k++;
        else{
            if(t>0) i+=k+1;
            else j+=k+1;
            if(i==j) ++j;
            k=0;
        }
    }
    return min(i,j);
}
const int maxn=1e6+6;
char s1[maxn],s2[maxn];
int main(){
    cin>>s1>>s2;
    int len=strlen(s1);
    int i=solve(s1),j=solve(s2);
    for(int k=0;k<len;k++){
        if(s1[(i+k)%len]!=s2[(j+k)%len]){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    for(int k=0;k<len;k++) cout<<s1[(i+k)%len];
    return 0;
}