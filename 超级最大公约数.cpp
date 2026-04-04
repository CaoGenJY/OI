#include<bits/stdc++.h>
using namespace std;
bool cmp(string &x,string &y){
    if(x.size()!=y.size()) return x.size()>y.size();
    for(int i=0;i<x.size();i++) if(x[i]!=y[i]) return x[i]>y[i];
    return 1;
}
string db2(string &x){
    int t=0;string ret="";
    for(int i=0;i<(int)x.size();i++){
        t=t*10+x[i]-'0';
        ret+=t/2+'0';
        t%=2;
    }
    int pt=0;
    while(pt<ret.size()-1&&ret[pt]=='0') pt++;
    return ret.substr(pt);
}
string tm2(string &x){
    int t=0;string res=x;
    for(int i=(int)res.size()-1;i>=0;i--){
        int tmp=(res[i]-'0')*2+t;
        res[i]=(tmp%10)+'0';
        t=tmp/10;
    }
    if(t>0) res.insert(0,1,t+'0');
    return res;
}
string minu(string &x,string &y){
    int t=0;string ret="";
    for(int i=1;i<=(int)x.size();i++){
        int nx=x[x.size()-i]-'0',ny=(i<=y.size()?y[y.size()-i]-'0':0);
        int tmp=nx-ny-t;
        t=(tmp<0?1:0);
        ret+=(tmp<0?tmp+10:tmp)+'0';
    }
    int pt=ret.size()-1;
    while(pt&&ret[pt]=='0') pt--;
    string rret="";
    for(int i=pt;i>=0;i--) rret+=ret[i];
    return rret;
}
string gcd(string x,string y){
    int cnt=0;
    while(x!=y){
        if(!cmp(x,y)) swap(x,y);
        if(y=="0") break;
        bool f1=(x.back()-'0')%2==0,f2=(y.back()-'0')%2==0;
        if(f1&&f2) {x=db2(x);y=db2(y);cnt++;}
        else if(f1) x=db2(x);
        else if(f2) y=db2(y);
        else x=minu(x,y);
    }
    while(cnt--) x=tm2(x);
    return x;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string x,y; cin>>x>>y;
    cout<<gcd(x,y);
    return 0;
}