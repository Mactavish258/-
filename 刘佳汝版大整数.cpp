#include<iostream>  //只能对于正数加减和比较，并且减的话前面要大于后面的 
#include<vector>
#include<stack>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
class BigInteger  
{
public:
	static const int base=100000000;
	static const int width=8;
	vector<int>s;
	BigInteger(long long num=0){*this=num;}   
	BigInteger operator=(long long num)
	{
		s.clear();
		do{
			s.push_back(num%base);
			num=num/base;
		}while(num>0);
		return *this;
	}
	BigInteger operator=(const string &str)    
	{
		s.clear();
		int x,len=(str.length()-1)/width+1;
		for(int i=0;i<len;i++){
			int end=str.length()-i*width;
			int start=max(0,end-width);
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);   			        
			s.push_back(x);
		}
		return *this;
	}
	friend ostream & operator<<(ostream &out,const BigInteger& x)   
	{
	out<<x.s.back();
	for(int i=x.s.size()-2;i>=0;i--){
		char buf[20];
		sprintf(buf,"%08d",x.s[i]);
		for(int j=0;j<int(strlen(buf));j++)
			out<<buf[j];
	}
	return out;
	}
	friend istream & operator>>(istream &in,BigInteger& x)  
	{
	string s;
	if(!(in>>s)) return in;
	x=s;
	return in;
	}
	BigInteger operator+(const BigInteger& b)const  
	{
		BigInteger c;
		c.s.clear();
		for(int i=0,g=0;;i++){
			if(g==0&&i>=s.size()&&i>=b.s.size()) break;
			int x=g;
			if(i<s.size()) x+=s[i];
			if(i<b.s.size()) x+=b.s[i];
			c.s.push_back(x%base);
			g=x/base;
		}
		return c;
	}
	BigInteger operator-(const BigInteger& b)   
	{
		BigInteger c;
		c.s.clear();
		if(*this>b){
			int i,g;
		for(i=0,g=0;;i++){
			if(g==0&&i>=b.s.size()) break;
			int x=g;
			if(s[i]<b.s[i]){
				s[i+1]-=1;
				s[i]=s[i]+base;
			}
			if(i<s.size()) x+=s[i];
			if(i<b.s.size()) x-=b.s[i];
			c.s.push_back(x%base);
			g=x/base;
		}
		int x=0;
		for(;i<s.size();i++){
			x+=s[i];
			c.s.push_back(x%base);
			x=x/base;
		}
		}
		return c;
	}
	bool operator<(const BigInteger& b)const   
	{
		if(s.size()!=b.s.size()) return s.size()<b.s.size();
		for(int i=s.size()-1;i>=0;i--)
			if(s[i]!=b.s[i]) return s[i]<b.s[i];
		return false;
	}
	bool operator>(const BigInteger& b)const   
	{
		return b<*this;
	}
	bool operator<=(const BigInteger& b)const
	{
		return !(b<*this);
	}
	bool operator>=(const BigInteger& b)const
	{
		return !(*this<b);
	}
	bool operator==(const BigInteger& b)const  
	{
		return !(b<*this)&&!(*this<b);
	}
	BigInteger operator+=(const BigInteger& b)
	{
		*this=(*this+b);
		return *this;
	}
	BigInteger operator-=(const BigInteger& b)
	{
		*this=(*this-b);
		return *this;
	}
};
int main(void)
{
	BigInteger a,b,c;
	cin>>a>>b;
	c=a*b;
	cout<<c;
	return 0;
}
