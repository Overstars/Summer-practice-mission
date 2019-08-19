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
