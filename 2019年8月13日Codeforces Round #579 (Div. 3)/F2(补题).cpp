#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
const int inf=0x3f3f3f3f;
int dp[105][50005];//dp[i][j]表示第i个b<0的任务,当前r=j,值表示取到b<0最多的数量
bool cmp(const pair<int,int> a,const pair<int,int> b)
{
	return a.first + a.second > b.first + b.second;
}
int main()
{
	int n,r,i,j;
	cin>>n>>r;
	vector<pair<int,int> > pos,neg;
	for(i=0;i<n;i++)
	{
		pair<int,int> tem;
		cin>>tem.first>>tem.second;
		if(tem.second>=0)
			pos.push_back(tem);
		else{
			neg.push_back(tem);
		}
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end(),cmp);
	int cnt=0;
	for(i=0;i<pos.size();i++)
	{
		if(r>=pos[i].first)
		{
			r+=pos[i].second;
			cnt++;
		}
		else
			break;
	}
	memset(dp,0,sizeof(dp));
	for(i=0;i<int(neg.size());i++)//第i项任务
	{
		for(j=0;j<=r;j++)//j为当前的等级
		{
			if(j>=neg[i].first&&j+neg[i].second>=0)//i合法,可以做
			{//更新做完i的状态
				dp[i+1][j+neg[i].second]=max(dp[i+1][j+neg[i].second],dp[i][j]+1);
			}
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		}
	}
	int maxneg=0;
	for(i=0;i<=r;i++)
		maxneg=max(maxneg,dp[int(neg.size())][i]);
	cout<<cnt+maxneg<<endl;
	return 0;
}
