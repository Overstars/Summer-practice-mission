这次div3打的有点菜啊
# [题目](http://codeforces.com/contest/1203)
[官方题解](https://codeforces.com/blog/entry/69108)
又开始了自闭后的补题，这次不把题面复制过来了，我感觉都不会看的，想看就去原网站吧[可怜][委屈][要哭了]
## A.Circle of Students
### 题意
小朋友们是否依次连成了顺/逆的环
### 思路
硬写
### AC的代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
int a[205];
int jud(int n,int x)
{
	if(n==1)
		return 1;
	for(int i=1;i<n;i++)
		if(a[(x+i)%n]!=i)
			break;
		else if(i==n-1)
			return 1;
	for(int i=1;i<=n;i++)
		if(a[(n+x-i)%n]!=i)
			break;
		else if(i==n-1)
			return 1;
	return 0;
}
int main()
{
	int t,n,loc;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]==1)
				loc=i;
			a[i]--;
		}
		if(jud(n,loc))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
```
## B. Equal Rectangles
### 题意
给你4n个木棒，能否构建n个面积相等的矩形。
### 思路
硬算
### AC的代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
int a[405];
int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<4*n;i++)
			scanf("%d",&a[i]);
		sort(a,a+4*n);
		int squ=a[0]*a[4*n-1];
		int i=0,j=4*n-1,flag=1;
		while(i<j)
		{
			if(a[i]!=a[i+1]||a[j]!=a[j-1]){
				flag=0;
				break;
			}
			if(a[i]*a[j]!=squ){
				flag=0;
				break;
			}
			i+=2;
			j-=2;
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
```


## [C. Common Divisors](http://codeforces.com/contest/1203/problem/C)
### 题意
给你n个数，求出能整除所有这n个数的数的个数。
### 思路
求出这n个数的最大公因数，在求出这个公因数的所有因数。
我比赛时就这么写的啊，为什么就T了呢[快哭了]
### AC的代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	long long n,temp;
	int i,j;
	while(cin>>n){
		cin>>temp;
		long long g=temp;
		for(i=1;i<n;i++)
		{
			scanf("%I64d",&temp);
			g=__gcd(g,temp);
		}
		int cnt=0;
		for(long long i=1;i*i<=g;i++)
		{
			if(g%i==0){
				cnt++;
				if(i!=g/i)
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
```
## [D1. Remove the Substring (easy version)](http://codeforces.com/contest/1203/problem/D1)&&[D2. Remove the Substring (hard version)](https://codeforces.com/contest/1203/problem/D2)
### 题意
给你字符串s和t，从s中移除尽量多的字符，保证t是s的子串。输出移除的最大连续串长度。
### 思路
上次div3D题就是字符串，又见字符串。
看到题解时一脸懵逼，看懂题解后大喊666

### AC的代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
char s[200005],t[200005];
int rg[200005];//记录t[i]尽量向s末尾靠对应字符s[rg[i]]
int main()
{
	cin>>s>>t;
	int i,j,slen=strlen(s),tlen=strlen(t);
	for(i=tlen-1;i>=0;i--)//预处理rg数组
	{
		int pos=slen-1;//指向s末尾
		if(i+1<tlen)//正在检查的不是倒数第一个
			pos=rg[i+1]-1;//从t[i+1]对应的rg[i+1]-1开始寻找
		while(s[pos]!=t[i])
			pos--;
		rg[i]=pos;
	}
	int ans=0,pos=0;
	for(i=0;i<slen;i++)//从前向后遍历s
	{
		int rpos=slen-1;//如果pos==tlen,则可以直接从s末尾删到rg[tlen]+1
		if(pos<tlen)//pos记录当前匹配到t[pos]
			rpos=rg[pos]-1;//:可删除字符串右端,t[pos]在s中对应最右位置
		ans=max(ans,rpos-i+1);
		if(pos>=tlen)
			break;
		if(pos<tlen&&t[pos]==s[i])//t[pos]匹配到了可行字符
			pos++;//t[pos]段的可删除字符串不会再有更长的了,匹配下一个t[pos]
	}
	cout<<ans<<endl;
	return 0;
}


```

## [E . Boxers](https://codeforces.com/contest/1203/problem/E)
### 题意
给你n个数，每个数可以+1或-1或不变，问你最后最多有多少种数。
### 思路
胡搞
### AC的代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define PI 3.14159265358979323846
#define e  2.7182818284590452354
#define ln_2 0.69314718055994530942
#define ln_10 2.30258509299404568402
using namespace std;
const int inf=0x3f3f3f3f;
int a[150010];
int main()
{
	int n,maxn=0,i,j,temp;
	cin>>n;
	while(n--){
		scanf("%d",&temp);
		a[temp]++;
		maxn=max(maxn,temp);
	}
	for(i=1;i<=maxn;i++)
	{
		if(a[i]==0&&a[i+1]>0)
		{
			a[i]++;
			a[i+1]--;
		}
	}
	for(i=maxn+1;i>=0;i--)
	{
		if(a[i]==0&&a[i-1]>0)
		{
			a[i]++;
			a[i-1]--;
		}
	}
	int cnt=0;
	for(i=1;i<=maxn+5;i++)
		if(a[i]>0)
			cnt++;
	cout<<cnt<<endl;
	return 0;
}
```

## [F1. Complete the Projects (easy version)](https://codeforces.com/contest/1203/problem/F1)
### 题意
初始等级为r，有n个任务，第i个任务需要等级>=ai才可以做，做完后等级变化bi。等级必须在任何时刻都>=0，问你有没有可能完成所有任务。
### 思路
将任务分成b>=0和b<0两组，b>=0组按所需等级从小到大排序。b<0组按a+b从大到小排序，因为每个任务都要做，做完这个任务之后的最低分数为a+b。
### AC的代码
```cpp
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
```
## [F2 - Complete the Projects (hard version)](https://codeforces.com/contest/1203/problem/F2)
### 题意
大概内容同上，本题不必判断是否能完成所有任务，输出最多可以完成的任务。
### 思路
贪心+DP。还是分为pos和neg两组。
先贪心求出最多能取pos的数量，得到最大r。
再用DP求出最多可以取得的neg的数量。
啊啊啊，我DP还不是很熟，自己看完题解魔改总是WA。[委屈]
### AC的代码
```cpp
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
```
2019年8月19日21点50分
