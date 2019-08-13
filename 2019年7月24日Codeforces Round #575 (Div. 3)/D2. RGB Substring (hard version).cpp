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
