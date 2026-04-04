#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200000+5;
int n,a[maxn];
int L[maxn],R[maxn];
stack<int>st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++){
        while(!st.empty()&&a[st.top()]>=a[i])st.pop();
        L[i]=st.empty()?0:st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();

    for(int i=n;i>=1;i--){
        while(!st.empty()&&a[st.top()]>a[i])st.pop();
        R[i]=st.empty()?n+1:st.top();
        st.push(i);
    }

    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=1ll*a[i]*(i-L[i])*(R[i]-i);
    }
    cout<<ans;
    return 0;
}
