开始艰难的补题大业
复制过来的数学公式有格式错误，建议到原网站阅读原题
[官方题解](https://codeforc.es/blog/entry/68655)
# A. Three Piles of Candies
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alice and Bob have received three big piles of candies as a gift. Now they want to divide these candies as fair as possible. To do this, Alice takes one pile of candies, then Bob takes one of the other two piles. The last pile is split between Alice and Bob as they want: for example, it is possible that Alice takes the whole pile, and Bob gets nothing from it.

After taking the candies from the piles, if Alice has more candies than Bob, she discards some candies so that the number of candies she has is equal to the number of candies Bob has. Of course, Bob does the same if he has more candies.

Alice and Bob want to have as many candies as possible, and they plan the process of dividing candies accordingly. Please calculate the maximum number of candies Alice can have after this division process (of course, Bob will have the same number of candies).

You have to answer qq independent queries.

Let's see the following example: [1,3,4][1,3,4]. Then Alice can choose the third pile, Bob can take the second pile, and then the only candy from the first pile goes to Bob — then Alice has 44 candies, and Bob has 44 candies.

Another example is [1,10,100][1,10,100]. Then Alice can choose the second pile, Bob can choose the first pile, and candies from the third pile can be divided in such a way that Bob takes 5454 candies, and Alice takes 4646 candies. Now Bob has 5555 candies, and Alice has 5656 candies, so she has to discard one candy — and after that, she has 5555 candies too.

### Input
The first line of the input contains one integer qq (1≤q≤10001≤q≤1000) — the number of queries. Then qq queries follow.

The only line of the query contains three integers a,ba,b and cc (1≤a,b,c≤10161≤a,b,c≤1016) — the number of candies in the first, second and third piles correspondingly.

### Output
Print qq lines. The ii-th line should contain the answer for the ii-th query — the maximum number of candies Alice can have after the division, if both Alice and Bob act optimally (of course, Bob will have the same number of candies).

### Example
inputCopy
4
1 3 4
1 10 100
10000000000000000 10000000000000000 10000000000000000
23 34 45
outputCopy
4
55
15000000000000000
51
## AC代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long t,a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		long long x=min(min(a,b),c),z=max(max(a,b),c),y=a+b+c-x-z,maxi=0;
        if(y-x>z)
			cout<<x+z<<endl;
		else
			cout<<y+(long long)((z-(y-x))/2)<<endl;
	}
	return 0;
}
```
# B. Odd Sum Segments
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array aa consisting of nn integers a1,a2,…,ana1,a2,…,an. You want to split it into exactly kk non-empty non-intersecting subsegments such that each subsegment has odd sum (i. e. for each subsegment, the sum of all elements that belong to this subsegment is odd). It is impossible to rearrange (shuffle) the elements of a given array. Each of the nn elements of the array aa must belong to exactly one of the kk subsegments.

Let's see some examples of dividing the array of length 55 into 33 subsegments (not necessarily with odd sums): [1,2,3,4,5][1,2,3,4,5] is the initial array, then all possible ways to divide it into 33 non-empty non-intersecting subsegments are described below:

[1],[2],[3,4,5][1],[2],[3,4,5];
[1],[2,3],[4,5][1],[2,3],[4,5];
[1],[2,3,4],[5][1],[2,3,4],[5];
[1,2],[3],[4,5][1,2],[3],[4,5];
[1,2],[3,4],[5][1,2],[3,4],[5];
[1,2,3],[4],[5][1,2,3],[4],[5].
Of course, it can be impossible to divide the initial array into exactly kk subsegments in such a way that each of them will have odd sum of elements. In this case print "NO". Otherwise, print "YES" and any possible division of the array. See the output format for the detailed explanation.

You have to answer qq independent queries.

### Input
The first line contains one integer qq (1≤q≤2⋅1051≤q≤2⋅105) — the number of queries. Then qq queries follow.

The first line of the query contains two integers nn and kk (1≤k≤n≤2⋅1051≤k≤n≤2⋅105) — the number of elements in the array and the number of subsegments, respectively.

The second line of the query contains nn integers a1,a2,…,ana1,a2,…,an (1≤ai≤1091≤ai≤109), where aiai is the ii-th element of aa.

It is guaranteed that the sum of nn over all queries does not exceed 2⋅1052⋅105 (∑n≤2⋅105∑n≤2⋅105).

### Output
For each query, print the answer to it. If it is impossible to divide the initial array into exactly kk subsegments in such a way that each of them will have odd sum of elements, print "NO" in the first line. Otherwise, print "YES" in the first line and any possible division of the array in the second line. The division can be represented as kk integers r1r1, r2r2, ..., rkrk such that 1≤r1<r2<⋯<rk=n1≤r1<r2<⋯<rk=n, where rjrj is the right border of the jj-th segment (the index of the last element that belongs to the jj-th segment), so the array is divided into subsegments [1;r1],[r1+1;r2],[r2+1,r3],…,[rk−1+1,n][1;r1],[r1+1;r2],[r2+1,r3],…,[rk−1+1,n]. Note that rkrk is always nn but you should print it anyway.

### Example
input
3
5 3
7 18 3 14 1
5 4
1 2 3 4 5
6 2
1 2 8 4 10 2
output
YES
1 3 5
NO
NO
## 题意
给你一段n个数的数组，使它恰好分割为k段，每段和都为奇数，输出任意一个可行情况的所有分割的右端元素序号。

emm，当时以为要输出所有情况，写了一发前缀和+DFS爆搜，改了半天都不对……

## 思路
偶数不会造成影响，无视即可，每个分段其中奇数必须有奇数个，那么一种成立的情况是使之前k-1个每段分到一个奇数，剩下奇数全部分到第k段，判断是否为奇数个即可。
## AC代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[200010];
int main()
{
	int t,i,n,k,odd;
	cin>>t;
	while(t--){
		cin>>n>>k;
		odd=0;
		for(i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			if(arr[i]%2==1)
				odd++;
		}
		if(odd>=k&&(odd-k+1)%2==1){
			puts("YES");
			int cnt=0;//记录输出的分组
			for(i=1;i<n;i++){
				if(cnt==k-1)
					break;
				if(arr[i]%2==1){
					printf("%d ",i);
					cnt++;
				}
			}
			printf("%d\n",n);
		}
		else
			puts("NO");
	}
	return 0;
}
```
# C. Robot Breakout
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
nn robots have escaped from your laboratory! You have to find them as soon as possible, because these robots are experimental, and their behavior is not tested yet, so they may be really dangerous!

Fortunately, even though your robots have escaped, you still have some control over them. First of all, you know the location of each robot: the world you live in can be modeled as an infinite coordinate plane, and the ii-th robot is currently located at the point having coordinates (xixi, yiyi). Furthermore, you may send exactly one command to all of the robots. The command should contain two integer numbers XX and YY, and when each robot receives this command, it starts moving towards the point having coordinates (XX, YY). The robot stops its movement in two cases:

either it reaches (XX, YY);
or it cannot get any closer to (XX, YY).
Normally, all robots should be able to get from any point of the coordinate plane to any other point. Each robot usually can perform four actions to move. Let's denote the current coordinates of the robot as (xcxc, ycyc). Then the movement system allows it to move to any of the four adjacent points:

the first action allows it to move from (xcxc, ycyc) to (xc−1xc−1, ycyc);
the second action allows it to move from (xcxc, ycyc) to (xcxc, yc+1yc+1);
the third action allows it to move from (xcxc, ycyc) to (xc+1xc+1, ycyc);
the fourth action allows it to move from (xcxc, ycyc) to (xcxc, yc−1yc−1).
Unfortunately, it seems that some movement systems of some robots are malfunctioning. For each robot you know which actions it can perform, and which it cannot perform.

You want to send a command so all robots gather at the same point. To do so, you have to choose a pair of integer numbers XX and YY so that each robot can reach the point (XX, YY). Is it possible to find such a point?

### Input
The first line contains one integer qq (1≤q≤1051≤q≤105) — the number of queries.

Then qq queries follow. Each query begins with one line containing one integer nn (1≤n≤1051≤n≤105) — the number of robots in the query. Then nn lines follow, the ii-th of these lines describes the ii-th robot in the current query: it contains six integer numbers xixi, yiyi, fi,1fi,1, fi,2fi,2, fi,3fi,3 and fi,4fi,4 (−105≤xi,yi≤105−105≤xi,yi≤105, 0≤fi,j≤10≤fi,j≤1). The first two numbers describe the initial location of the ii-th robot, and the following four numbers describe which actions the ii-th robot can use to move (fi,j=1fi,j=1 if the ii-th robot can use the jj-th action, and fi,j=0fi,j=0 if it cannot use the jj-th action).

It is guaranteed that the total number of robots over all queries does not exceed 105105.

### Output
You should answer each query independently, in the order these queries appear in the input.

To answer a query, you should do one of the following:

if it is impossible to find a point that is reachable by all nn robots, print one number 00 on a separate line;
if it is possible to find a point that is reachable by all nn robots, print three space-separated integers on the same line: 11 XX YY, where XX and YY are the coordinates of the point reachable by all nn robots. Both XX and YY should not exceed 105105 by absolute value; it is guaranteed that if there exists at least one point reachable by all robots, then at least one of such points has both coordinates not exceeding 105105 by absolute value.
## 题意
在平面直角坐标系中有n(n<=1e5)个机器人，第i个坐标为 (xi, yi)，有的机器人运动系统有故障，$f$i,j=0代表第i个机器人不能向j方向前进，你要计算出全部机器人都可以到达的点(X,Y)。
## 思路
模拟，逐步缩小范围，最后输出边界即可，注意边界范围
## AC代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=100000;
int main()
{
	int t,n,i,x,y,w,a,s,d,flag;
	cin>>t;
	while(t--){
		flag=1;
		int xmin=-inf,xmax=inf,ymin=-inf,ymax=inf;
		cin>>n;
		while(n--){
			scanf("%d%d%d%d%d%d",&x,&y,&a,&w,&d,&s);
			if(!a)
				xmin=max(xmin,x);
			if(!w)
				ymax=min(ymax,y);
			if(!d)
				xmax=min(xmax,x);
			if(!s)
				ymin=max(ymin,y);
			if(xmin>xmax||ymin>ymax){
				flag=0;
			}
		}
		!flag?puts("0"):printf("1 %d %d\n",xmax,ymax);
	}
	return 0;
}
```
# D1. RGB Substring (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The only difference between easy and hard versions is the size of the input.

You are given a string ss consisting of nn characters, each character is 'R', 'G' or 'B'.

You are also given an integer kk. Your task is to change the minimum number of characters in the initial string ss so that after the changes there will be a string of length kk that is a substring of ss, and is also a substring of the infinite string "RGBRGBRGB ...".

A string aa is a substring of string bb if there exists a positive integer ii such that a1=bia1=bi, a2=bi+1a2=bi+1, a3=bi+2a3=bi+2, ..., a|a|=bi+|a|−1a|a|=bi+|a|−1. For example, strings "GBRG", "B", "BR" are substrings of the infinite string "RGBRGBRGB ..." while "GR", "RGR" and "GGG" are not.

You have to answer qq independent queries.

### Input
The first line of the input contains one integer qq (1≤q≤20001≤q≤2000) — the number of queries. Then qq queries follow.

The first line of the query contains two integers nn and kk (1≤k≤n≤20001≤k≤n≤2000) — the length of the string ss and the length of the substring.

The second line of the query contains a string ss consisting of nn characters 'R', 'G' and 'B'.

It is guaranteed that the sum of nn over all queries does not exceed 20002000 (∑n≤2000∑n≤2000).

### Output
For each query print one integer — the minimum number of characters you need to change in the initial string ss so that after changing there will be a substring of length kk in ss that is also a substring of the infinite string "RGBRGBRGB ...".
## 题意
给你一个长度为n的字符串s并修改其中字符，使得其存在长度为k的子串同时为无限字符串"RGB……"的子串，求出需要修改的最小个数。
## 思路
从s串前n-k个位置开始枚举长度为k的子串，分别与以R,G,B开头的无限字符串进行比较，记录不同的字母数量。输出其中最小的不同字母数，即为答案。
## AC代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	int t,n,k;
	const string rgb="RGB";
	cin>>t;
	while(t--){
		string s;
		int ans=inf;
		cin>>n>>k>>s;//s长度,子串长度,s
		for(int i=0;i<n-k+1;i++){//从i开始枚举子串
			for(int j=0;j<3;j++){//分别从R,G,B开始比较
				int change=0;
				for(int pos=0;pos<k;pos++){
					if(s[i+pos]!=rgb[(j+pos)%3])
						change++;//若不同,则改变
				}
				ans=min(ans,change);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
```
# D2. RGB Substring (hard version)
## 题意
和上面一样，不过卡掉了暴力方案，好题
## 思路
十分强悍的前缀和思想，分别以R、G、B开头三次计算匹配改动字符数量的前缀和到rec数组，每算完一种便寻找最小解，三次计算结束后即为答案。目测复杂度O(2n-k)
## AC的代码
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f,maxn=500005;
char str[maxn],rgb[4]="RGB";//前缀和思维题
int rec[maxn];
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;//字符串长度为n,选取长度为k的子串
		scanf("%s",str);
//		memset(rec,0,sizeof(rec));
		int ans=inf;
		for(int i=0;i<3;i++)
		{
			if(str[0]!=rgb[i])
				rec[0]=1;
			else
				rec[0]=0;
			for(int j=1;j<n;j++)
			{
				if(str[j]!=rgb[(i+j)%3])
					rec[j]=rec[j-1]+1;
				else
					rec[j]=rec[j-1];
			}
			ans=min(ans,rec[k-1]);
			for(int j=k;j<n;j++)
				ans=min(ans,rec[j]-rec[j-k]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
```

# [E. Connected Component on a Chessboard](https://codeforc.es/contest/1196/problem/E)
## 题意
给你一个1e9 * 1e9大小的黑白相间的棋盘，(1,1)为白色。（就是这个棋盘中的一块格子上下左右颜色不同，斜方向颜色相同）。
多组询问≤1e5，一组两个整数b和w（1≤b,w≤1e5），要求输出由b个黑块和w个白块组成的联通块方案。可行的话，输出YES及每一个块的位置坐标(任意一种即可)，否则输出NO。
## 思路
### 如何判断：
找规律可以看出，一种颜色最多能与3*n+1块异色块联通，所以可以通过max(b,w)>3 *min(b,w)+1判断是否存在方案。题解的下面评论区有大佬证明
### 如何输出一种方案：
来看题解给出的方案，假如b>w，我们先选择白块，（2，2），每隔一块选择直到（2，2w），这一段可以直接输出（两个白块中间夹着一个黑块，条形共2w-1块黑，w块白）。我们将剩下的b-=2w-1黑块摆放在白块的左右两侧位置及上下即可。
## AC的代码
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
	int t;
	cin>>t;
	while(t--){
		int b,w,x,y;
		cin>>b>>w;
		if(max(b,w)>min(b,w)*3+1)
			puts("NO");
		else{
			puts("YES");
			int blackless;
			if(b>w)//
				x=2,y=2,blackless=0;
			else
				x=2,y=3,blackless=1,swap(b,w);
			for(int i=2;i<=2*w;i++)
				printf("%d %d\n",x,y++);
			b-=w-1;
			if(b>0)//条形上部有个位置
			{
				if(blackless)
					printf("2 2\n");
				else
					printf("2 1\n");
				b--;
			}
			if(b>0)//下部也有个位置
			{
				printf("%d %d\n",x,y++);
				b--;
			}
			x--,y-=2;
			while(b>0&&y>1)//填充左侧
			{
				printf("%d %d\n",x,y);
				y-=2;
				b--;
			}
			x+=2;
			if(blackless)
				y=3;
			else
				y=2;
			while(b>0)//剩下的全部输出
			{
				printf("%d %d\n",x,y);
				y+=2;
				b--;
			}
		}
	}
	return 0;
}
```
# [F. K-th Path](https://codeforc.es/contest/1196/problem/F)
## 题意
n节点,m条边,打印第k条最短路
## 思路
若k>m，则要将整个表跑floyd，涉及到的点最多有2m个。
若k<=m，排序，将前k条边跑floyd，第k小肯定是在前k个边的组合之中产生的。需要进行离散化处理。
注意求和会卡掉int，要用long long
## 为自己的弱小找借口
其实我还不会用离散化处理……这题各节点没必要保留相对大小，只需区分出不同节点，所以先偷个懒不学离散化，用map映射各点代替一下。用dijkstra跑n遍也应该可以，不过可能会有重复路径要特殊处理，没有floyd直截了当。
## AC的代码
```cpp
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
```

2019年8月13日13点16分补完
