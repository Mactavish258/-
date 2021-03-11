#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int ouler_phi()
{
	int ans=n;
	int m=(int)sqrt(n+0.5);
	for(int i=2;i<=m;++i)
	{
		if(ans%i==0)
		{
			ans=ans/i*(i-1);
			while(n%i==0)
			n/=i;
		}
	}
	if(n>1)
	ans=ans/n*(n-1);
	return ans;
}
int main(void)
{
	cin>>n;
	cout<<ouler_phi();
	return 0;
}
