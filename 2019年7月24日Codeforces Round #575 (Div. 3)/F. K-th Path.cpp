#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=200005;
struct edge
{
	int u,v,w;
} e[MAXN];
long long path[805][805],rec[405];
bool cmp(edge x,edge y)//Floyd-Warshall算法求所有点对之间的最短距离,复杂度O(n^3)
{
	return x.w<y.w;
}
void floyd(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(path[i][k]+path[k][j]<path[i][j])
                {
                    path[i][j]=path[i][k]+path[k][j];//当i，j的原来的边的最短距离，大于经过k点所到达的距离那么就替换。

                }
            }
}
int main()
{
	int n,m,k;//n节点,m条边,打印第k条最短路
	while(cin>>n>>m>>k){
		int x,y,w;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		sort(e,e+m,cmp);//只需将min(k,m)跑一下最短路
		memset(path,inf,sizeof(path));
		map<int,int> TAT;//离散化不会，用map代替一下QAQ
		int cnt=0;
		for(int i=0;i<min(k,m);i++)//离散化处理不太会
		{//cnt<=2*min(k,m)
			if(TAT[e[i].u]==0)
				TAT[e[i].u]=++cnt;
			if(TAT[e[i].v]==0)
				TAT[e[i].v]=++cnt;
			int a=TAT[e[i].u],b=TAT[e[i].v];
			path[a][b]=path[b][a]=e[i].w;
		}
		for(int i=1;i<=cnt;i++)//自己到自己
			path[i][i]=0;
		floyd(cnt);//节点个数cnt个
		int cnt2=0;
		for(int i=1;i<=cnt;i++)//写成这样dijkstra跑n遍也应该可以
			for(int j=1;j<i;j++)
				rec[cnt2++]=path[i][j];
		sort(rec,rec+cnt2);
		cout<<rec[k-1]<<endl;
	}
	return 0;
}
