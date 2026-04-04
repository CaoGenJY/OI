#include<bits/stdc++.h>
using namespace std;
struct node{
    char c;
    bool matched;
};
stack<node> stk;
int Q,op,open,cls;
char c;
int main(){
    cin>>Q;
    for(int i=1;i<=Q;i++){
        cin>>op;
        if(op==1){
            cin>>c;
            if(c=='('){
                open++;
                stk.push({c,0});
            }
            else{
                if(open){
                    open--;
                    stk.push({c,1});
                }
                else{
                    cls++;
                    stk.push({c,0});
                }
            }
        }else{
            node tp=stk.top();
            stk.pop();
            if(tp.c=='(') open--;
            else{
                if(tp.matched) open++;
                else cls--;
            }
        }
        if(!open&&!cls) puts("Yes");
        else puts("No");
    }
    return 0;
}
