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
