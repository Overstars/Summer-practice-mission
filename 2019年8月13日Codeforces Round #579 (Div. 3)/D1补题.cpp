#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
char s[200005],t[200005];
int rg[200005];//��¼t[i]������sĩβ����Ӧ�ַ�s[rg[i]]
int main()
{
	cin>>s>>t;
	int i,j,slen=strlen(s),tlen=strlen(t);
	for(i=tlen-1;i>=0;i--)//Ԥ����rg����
	{
		int pos=slen-1;//ָ��sĩβ
		if(i+1<tlen)//���ڼ��Ĳ��ǵ�����һ��
			pos=rg[i+1]-1;//��t[i+1]��Ӧ��rg[i+1]-1��ʼѰ��
		while(s[pos]!=t[i])
			pos--;
		rg[i]=pos;
	}
	int ans=0,pos=0;
	for(i=0;i<slen;i++)//��ǰ������s
	{
		int rpos=slen-1;//���pos==tlen,�����ֱ�Ӵ�sĩβɾ��rg[tlen]+1
		if(pos<tlen)//pos��¼��ǰƥ�䵽t[pos]
			rpos=rg[pos]-1;//:��ɾ���ַ����Ҷ�,t[pos]��s�ж�Ӧ����λ��
		ans=max(ans,rpos-i+1);
		if(pos>=tlen)
			break;
		if(pos<tlen&&t[pos]==s[i])//t[pos]ƥ�䵽�˿����ַ�
			pos++;//t[pos]�εĿ�ɾ���ַ����������и�������,ƥ����һ��t[pos]
	}
	cout<<ans<<endl;
	return 0;
}
