#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
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
