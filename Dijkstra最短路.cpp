#include<iostream>  //2021.2.3
#include<cstdio>    //Dijkstra最短路松弛操作 时间复杂度mlogn,边全都是正权才行 
#include<vector>   
#include<queue>
using namespace std;
struct edge{  //边 
	int from,to,dist;
	edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct headnode{  //某点与达到某点的最短路径 
	int u,d;
	bool operator<(const headnode&s)const{
		return s.d<d;
	}
};
struct Dijkstra{
	int n,m;
	vector<edge>edges;  //边集 
	vector<int>line[100005];  //每个点为起点指向下一条边的在边集中的下标 
	int d[100005];  //起点到各点的距离 
	int p[100005];  //最短路上的一条弧 
	
	void init(int n)  //初始化 
	{
		this->n=n;
		for(int i=0;i<=n;++i)
		line[i].clear();
		edges.clear();
	}
	
	void addedge(int u,int v,int d)  //加入一条边 
	{  
		edges.push_back(edge(u,v,d));
		m=edges.size();
		line[u].push_back(m-1);
	}
	
	void dijkstra(int s)  //Dijkstra算法 
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
			if(x.d!=d[x.u])continue;  //如果已经遍历过该点 
			for(int i=0;i<line[u].size();++i)
			{
				edge &e=edges[line[u][i]];
				if(x.d+e.dist<d[e.to])
				{
					d[e.to]=x.d+e.dist;  //设置下一个点的距离 
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
