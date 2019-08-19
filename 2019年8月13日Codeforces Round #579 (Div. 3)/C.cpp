#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;//求所有最大公因数
const int inf=0x3f3f3f3f;
long long gcd(long long a,long long b)
{
	if(a<b)
		swap(a,b);
	long long r;
	while((r=a%b)){
		a=b;
		b=r;
	}
	return b;
}
bool QAQ[1000000000005];
int main()
{
	long long n,i;
	long long a,cnt=0;
	cin>>n;
	scanf("%I64d",&a);
	for(i=1;i<=sqrt(a);i++)
	{
		if(a%i==0)
			if(i==sqrt(a)&&a/i==i){
				cnt++;
				QAQ[i]=1;
			}
			else{
				cnt+=2;
				QAQ[i]=QAQ[a/i]=1;
			}
	}
	for(i=1;i<n;i++)
	{
		scanf("%I64d",&a);
		for(long long j=2;j<=a;j++)
		{
			if(a%j!=0&&QAQ[j]==1){
				cnt--;
				QAQ[j]=0;
			}
			if(cnt==1)
				goto label;
		}
	}
	label:
	cout<<cnt<<endl;
	return 0;
}
