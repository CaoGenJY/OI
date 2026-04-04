#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std; 
struct node{
	int x,y,h;
}a[201];
bool f[201];
int n,m,x,y,t,cnt,head[2001],u,v,w;
struct Edge{
    int w,nxt,to;
}edge[201*201];
int hh(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].x==x)
		return i;
	}
}
void add(int u,int v,int w)
{
    edge[++cnt].to=v;
    edge[cnt].nxt=head[u];
    edge[cnt].w=w;
    head[u]=cnt;
}
int main() 
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].h);
		a[i].h+=a[i].y;
	}
	f[1]=1;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		w=hh(u+w);
		u=hh(u-1);
        add(u,w,v);
		add(w,u,v);
	}
	scanf("%d%d",&x,&y);
	while(1) 
	{
		bool ff=1;
        while(ff)
        {
            ff=0;
            for(int i=1;i<=n;i++)
            {
            	if(f[i])
        		{
            		for(int j=head[i];j;j=edge[j].nxt)
		           	{
					   	if(a[i].h<=edge[j].w&&!f[edge[j].to])
			            f[edge[j].to]=ff=1;
					} 
				}
			}
        }
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i])
			    maxn=max(maxn,a[i].h);
			if(f[x]&&maxn==y)
			{
				cout<<t<<endl;
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]&&a[i].y==a[i].h&&a[i].y==maxn)
			{
				cout<<"-1";
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]&&a[i].h==maxn)
			{
				a[i].h--;
				t++;
			}
		}
	}
	return 0;
}
