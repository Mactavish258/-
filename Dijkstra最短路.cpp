#include<iostream>  //2021.2.3
#include<cstdio>    //Dijkstra���·�ɳڲ��� ʱ�临�Ӷ�mlogn,��ȫ������Ȩ���� 
#include<vector>   
#include<queue>
using namespace std;
struct edge{  //�� 
	int from,to,dist;
	edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct headnode{  //ĳ����ﵽĳ������·�� 
	int u,d;
	bool operator<(const headnode&s)const{
		return s.d<d;
	}
};
struct Dijkstra{
	int n,m;
	vector<edge>edges;  //�߼� 
	vector<int>line[100005];  //ÿ����Ϊ���ָ����һ���ߵ��ڱ߼��е��±� 
	int d[100005];  //��㵽����ľ��� 
	int p[100005];  //���·�ϵ�һ���� 
	
	void init(int n)  //��ʼ�� 
	{
		this->n=n;
		for(int i=0;i<=n;++i)
		line[i].clear();
		edges.clear();
	}
	
	void addedge(int u,int v,int d)  //����һ���� 
	{  
		edges.push_back(edge(u,v,d));
		m=edges.size();
		line[u].push_back(m-1);
	}
	
	void dijkstra(int s)  //Dijkstra�㷨 
	{
		for(int i=0;i<=n;++i)
		d[i]=0x7fffffff;
		d[s]=0;
		priority_queue<headnode>qu;
		qu.push((headnode){s,0});
		while(!qu.empty())
		{
			headnode x=qu.top(); qu.pop();
			int u=x.u;
			if(x.d!=d[x.u])continue;  //����Ѿ��������õ� 
			for(int i=0;i<line[u].size();++i)
			{
				edge &e=edges[line[u][i]];
				if(x.d+e.dist<d[e.to])
				{
					d[e.to]=x.d+e.dist;  //������һ����ľ��� 
					p[e.to]=line[u][i];
					qu.push((headnode){e.to,d[e.to]});
				}
			}
		}
	}
};
int main(void)
{
	Dijkstra me;
	int n,m,s;
	int a,b,c;
	cin>>n>>m>>s;
	me.init(n); 
	for(int i=0;i<m;++i)
	{
		cin>>a>>b>>c;
		me.addedge(a,b,c);
	}
	me.dijkstra(s);
	for(int i=1;i<=n-1;++i)
	cout<<me.d[i]<<" ";
	cout<<me.d[n]; 
	return 0;
}
