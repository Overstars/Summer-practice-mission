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
