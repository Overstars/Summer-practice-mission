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
