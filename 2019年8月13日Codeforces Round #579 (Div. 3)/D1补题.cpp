#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
char s[200005],t[200005];
int rg[200005];//记录t[i]尽量向s末尾靠对应字符s[rg[i]]
int main()
{
	cin>>s>>t;
	int i,j,slen=strlen(s),tlen=strlen(t);
	for(i=tlen-1;i>=0;i--)//预处理rg数组
	{
		int pos=slen-1;//指向s末尾
		if(i+1<tlen)//正在检查的不是倒数第一个
			pos=rg[i+1]-1;//从t[i+1]对应的rg[i+1]-1开始寻找
		while(s[pos]!=t[i])
			pos--;
		rg[i]=pos;
	}
	int ans=0,pos=0;
	for(i=0;i<slen;i++)//从前向后遍历s
	{
		int rpos=slen-1;//如果pos==tlen,则可以直接从s末尾删到rg[tlen]+1
		if(pos<tlen)//pos记录当前匹配到t[pos]
			rpos=rg[pos]-1;//:可删除字符串右端,t[pos]在s中对应最右位置
		ans=max(ans,rpos-i+1);
		if(pos>=tlen)
			break;
		if(pos<tlen&&t[pos]==s[i])//t[pos]匹配到了可行字符
			pos++;//t[pos]段的可删除字符串不会再有更长的了,匹配下一个t[pos]
	}
	cout<<ans<<endl;
	return 0;
}
