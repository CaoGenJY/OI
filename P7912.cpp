#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct blk{
    int l,r,val;
};
int n;
bool a[maxn],used[maxn];
queue<blk> q,tmp;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int j=i; while(j+1<=n&&a[j+1]==a[i]) j++;
        q.push({i,j,a[i]}); 
        i=j;
    }
    int lst=n;
    while(lst){
        while(!q.empty()){
            blk ft=q.front();
            q.pop();
            while(used[ft.l]&&ft.l<=ft.r) ft.l++;
            if(ft.l>ft.r) continue;
            used[ft.l]=1;
            cerr<<ft.l<<' ';
            lst--;
            if(ft.l==ft.r) continue;
            ft.l++;
            tmp.push(ft);
        }
        while(!tmp.empty()){
            blk ft=tmp.front(); tmp.pop();
            if(!tmp.empty()){
                blk fft=tmp.front();
                if(fft.val==ft.val){
                    ft.r=fft.r;
                    tmp.pop();
                }else break;
            }
            q.push(ft);
        }
    }
    return 0;
}