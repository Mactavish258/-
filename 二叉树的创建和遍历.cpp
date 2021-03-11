#include<iostream>  //2020.10.22 
#include<queue>
using namespace std;
int n;
struct node{
	int info;
	node *lchild,*rchild;
};
int ar[7]={4,2,1,3,5,7,6};
int br[7]={1,2,3,4,5,6,7};
int cr[7]={1,3,2,6,7,5,4};

node *fmcreattree(int ar[],int br[],int n)  //由前序和中序创建二叉树 
{
	if(n==0)
	return NULL;
	node *bt=new node;
	bt->info=ar[0];
	int k;
	for(k=0;k<n;++k)
	if(br[k]==ar[0])
	break;
	bt->lchild=fmcreattree(ar+1,br,k);
	bt->rchild=fmcreattree(ar+k+1,br+k+1,n-k-1);
	return bt;
} 

node *mbcreattree(int br[],int cr[],int n)  //由中序和后序创建二叉树 
{
	if(n==0)
	return NULL;
	node *bt=new node;
	bt->info=cr[n-1];
	int k;
	for(k=0;k<n;++k)
	if(bt->info==br[k])
	break;
	bt->lchild=mbcreattree(br,cr,k);
	bt->rchild=mbcreattree(br+k+1,cr+k,n-k-1);
	return bt;
} 

void fdfs(node *bt)  //前序遍历 
{
	if(bt==NULL)
	return;
	cout<<bt->info<<" ";
	fdfs(bt->lchild);
	fdfs(bt->rchild);
}
void mdfs(node *bt)  //中序遍历 
{
	if(bt==NULL)
	return;
	mdfs(bt->lchild);
	cout<<bt->info<<" ";
	mdfs(bt->rchild);	
}
void bdfs(node *bt)  //后序遍历 
{
	if(bt==NULL)
	return;
	bdfs(bt->lchild);
	bdfs(bt->rchild);
	cout<<bt->info<<" ";
}
void bfs(node *bt)  //从上到下，从左到右的顺序遍历 (标准广搜)
{
	queue<node *>qu;
	qu.push(bt);
	node *ar;
	while(!qu.empty())
	{
		ar=qu.front();
		qu.pop();
		if(ar==NULL)
		continue;
		cout<<ar->info<<" ";
		qu.push(ar->lchild);
		qu.push(ar->rchild);
	}
}
int main(void)
{
	cin>>n;
	node *bt=fmcreattree(ar,br,n);
	bdfs(bt);
	return 0;
 } 
