#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int shu[50000];
int vis[10000];
int n,cnt,sum;
void ouler()
{
	for(int i=2;i<=n;++i)
	{
		if(!vis[i])
			shu[++sum]=i;
		for(int j=1;j<=sum&&i*shu[j]<=n;++j)
		{
			vis[i*shu[j]]=1;
			if(i%shu[j]==0)
			break;
		}
	}
}
int main(void)
{
	cin>>n;
	ouler();
	for(int i=1;i<=sum;++i)
	cout<<shu[i]<<endl;
}
