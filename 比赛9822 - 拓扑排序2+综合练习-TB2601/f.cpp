#include<bits/stdc++.h>
using namespace std;
struct person{
    string uid;
    int id,score;
    bool operator<(const person& x) const{
        if(score!=x.score) return score>x.score;
        return id<x.id;
    }

};
set<person> st;
map<string,int> mp;
int n,idx=0;

int string_to_int(string s){
    int ret=0;
    for(int i=0;i<(int)s.size();i++){
        ret=ret*10+s[i]-'0';
    }
    return ret;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char op; string s; int i1=0,id=0;
        cin>>op>>s;
        if(mp.count(s)) id=mp[s];
        else{
            mp[s]=++idx;
            id=idx;
        }

        if(op=='+'){
            cin>>i1;
            bool flg=false;
            person oldp;
            for(person p:st){
                if(p.id==id){
                    flg=true;
                    oldp=p;
                    break;
                }
            }
            if(flg){
                st.erase(oldp);
                oldp.score=i1;
                st.insert(oldp);
            }else{
                st.insert({s,id,i1});
            }
        }else{
            if(s[0]>='0'&&s[0]<='9'){
                int rk=string_to_int(s);
                int cnt=0;
                for(person p:st){
                    cnt++;
                    if(cnt>rk+9) break;
                    if(cnt>=rk){
                        cout<<p.uid<<' ';
                    }
                }
                cout<<'\n';
            }else{
                int cnt=0;
                for(person p:st){
                    cnt++;
                    if(p.uid==s){
                        cout<<cnt<<'\n';
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
