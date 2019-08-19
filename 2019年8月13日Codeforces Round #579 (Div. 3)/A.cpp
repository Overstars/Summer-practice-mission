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
