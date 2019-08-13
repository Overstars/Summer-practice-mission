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
bool cmp(edge x,edge y)//Floyd-Warshall�㷨�����е��֮�����̾���,���Ӷ�O(n^3)
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
                    path[i][j]=path[i][k]+path[k][j];//��i��j��ԭ���ıߵ���̾��룬���ھ���k��������ľ�����ô���滻��

                }
            }
}
int main()
{
	int n,m,k;//n�ڵ�,m����,��ӡ��k�����·
	while(cin>>n>>m>>k){
		int x,y,w;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		sort(e,e+m,cmp);//ֻ�轫min(k,m)��һ�����·
		memset(path,inf,sizeof(path));
		map<int,int> TAT;//��ɢ�����ᣬ��map����һ��QAQ
		int cnt=0;
		for(int i=0;i<min(k,m);i++)//��ɢ������̫��
		{//cnt<=2*min(k,m)
			if(TAT[e[i].u]==0)
				TAT[e[i].u]=++cnt;
			if(TAT[e[i].v]==0)
				TAT[e[i].v]=++cnt;
			int a=TAT[e[i].u],b=TAT[e[i].v];
			path[a][b]=path[b][a]=e[i].w;
		}
		for(int i=1;i<=cnt;i++)//�Լ����Լ�
			path[i][i]=0;
		floyd(cnt);//�ڵ����cnt��
		int cnt2=0;
		for(int i=1;i<=cnt;i++)//д������dijkstra��n��ҲӦ�ÿ���
			for(int j=1;j<i;j++)
				rec[cnt2++]=path[i][j];
		sort(rec,rec+cnt2);
		cout<<rec[k-1]<<endl;
	}
	return 0;
}
