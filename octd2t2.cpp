#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,ans;
string s;
string to(int num) {
    vector<pair<int, string>> ys={
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
        {100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
        {10,"X"},{9,"IX"},{5,"V"},{4,"IV"},
        {1,"I"}
    };
    string ret="";
    for(const pair<int,string> p:ys){
        while(num>=p.first) num-=p.first,ret+=p.second;
    }
    return ret;
}

int main(){
    // freopen("roman.in","r",stdin);
    // freopen("roman.out","w",stdout);
    cin>>n;
    for(int u=1;u<=n;u++){
        cin>>s;
        int num=0;
        for(int i=0;i<s.size();i++){
            bool flg=false;
            if(i!=s.size()-1){
                if(s[i]=='I'&&s[i+1]=='V') num+=4,flg=true;
                if(s[i]=='I'&&s[i+1]=='X') num+=9,flg=true;
                if(s[i]=='X'&&s[i+1]=='L') num+=40,flg=true;
                if(s[i]=='X'&&s[i+1]=='C') num+=90,flg=true;
                if(s[i]=='C'&&s[i+1]=='D') num+=400,flg=true;
                if(s[i]=='C'&&s[i+1]=='M') num+=900,flg=true;
            }
            if(!flg){
                if(s[i]=='I') num++;
                if(s[i]=='V') num+=5;
                if(s[i]=='X') num+=10;
                if(s[i]=='L') num+=50;
                if(s[i]=='C') num+=100;
                if(s[i]=='D') num+=500;
                if(s[i]=='M') num+=1000;
            }else i++;
        }
        ans+=num;
    }
    if(ans>=4000){
        puts("ERROR");
        return 0;
    }
    cout<<to(ans)<<endl;
    return 0;
}