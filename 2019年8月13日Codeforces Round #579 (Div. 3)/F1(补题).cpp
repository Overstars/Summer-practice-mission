#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
const int inf=0x3f3f3f3f;
struct node
{
	int a,b;//需要等级,等级变化
};
struct cmp
{
	bool operator() (node x,node y)
	{
		return x.a>y.a;//把需要等级小的放在堆顶
	}
};
struct cmp2//neg数组
{
	bool operator() (node x,node y)
	{
		return x.a+x.b<y.a+y.b;//做完这个任务的最低分数[a+b,+∞)
        //因为每个任务都要做,所以我们按a+b从大到小排序即可
	}
};
int main()
{
	int n,r,i,j,flag=1;//保证等级始终>0&&>a[i]
	node tem;
	cin>>n>>r;
	priority_queue<node,vector<node>,cmp>pos;
	priority_queue<node,vector<node>,cmp2>neg;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&tem.a,&tem.b);
		if(tem.b>=0)
			pos.push(tem);
		else
			neg.push(tem);
	}
	while(!pos.empty())
	{
		tem=pos.top();
		pos.pop();
//		printf("1.a=%d,b=%d,r=%d\n",tem.a,tem.b,r);
		if(r<tem.a)
		{
			flag=0;
			goto label;
		}
		r+=tem.b;
	}
	while(!neg.empty())
	{
		tem=neg.top();
		neg.pop();
//		printf("2.a=%d,b=%d,r=%d\n",tem.a,tem.b,r);
		if(r<tem.a)
		{
			flag=0;
			goto label;
		}
		r+=tem.b;
		if(r<0)
		{
			flag=0;
			goto label;
		}
	}
	label:
		cout<<(flag?"YES":"NO")<<endl;
	return 0;
}
