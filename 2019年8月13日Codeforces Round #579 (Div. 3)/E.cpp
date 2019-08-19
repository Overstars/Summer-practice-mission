#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
int a[150005],b[150005],c[150005];
int main()
{
	int n,temp,maxn=0,cnt=0,cnt2=0;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a[temp]++;
//		scanf("%d",&a[i]);
		maxn=max(maxn,temp);
	}
	for(int i=0;i<=maxn;i++)
		b[i]=a[i];
	for(int i=0;i<maxn;i++){
		if(b[i]+c[i]>0)
			cnt++;
		if(b[i+1]+c[i+1]==0&&b[i]>1){
			b[i]--;
			c[i+1]++;
		}
	}
	memset(c,0,sizeof(c));
	for(int i=maxn;i>0;i--){
		if(a[i]+c[i]>0)
			cnt2++;
		if(a[i-1]+c[i-1]==0&&a[i]>1){
			a[i]--;
			c[i-1]++;
		}
	}
	cout<<max(cnt,cnt2)<<endl;
	return 0;
}
