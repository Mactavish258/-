#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int phi[10005];
void ouler_table()
{
	phi[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!phi[i])
		for(int j=i;j<=n;j+=i)
		{
			if(!phi[j])
			phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
	}
}
int main(void)
{
	cin>>n;
	ouler_table();
	for(int i=1;i<=n;++i)
	cout<<i<<"  "<<phi[i]<<endl;
	return 0;
}
