#include<iostream>  //2021.2.4   �߾��ȳ˷� (����ģ��)
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
string str,s1,s2;
int lena,lenb,len;
int jin,now;
int num[5005];  //num[1]�Ǹ�λ����num[2]��ʮλ�����Դ����� 
int main(void)
{
	cin>>s1>>s2;
	lena=s1.size();
	lenb=s2.size();
	len=lena+lenb;
	if(s1=="0"||s2=="0")
	{cout<<0;
	return 0;
	}
	
	for(int i=lena-1;i>=0;--i)
	{
		for(int j=lenb-1;j>=0;--j)
		{
			num[(lena-i)+(lenb-j)-1]+=(s1[i]-48)*(s2[j]-48);
		}
	}
	for(int i=1;i<=len;++i)  //�߾��ȼӷ����� 
	{
		num[i]+=jin;
		jin=num[i]/10;
		num[i]%=10;
	}
	int i=5000;
	while(!num[i])--i;
	for(int j=i;j>=1;--j)  //�Ӹ�λ����λ��� 
	cout<<num[j];
	return 0;
} 
