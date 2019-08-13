#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	int t,n,k;
	const string rgb="RGB";
	cin>>t;
	while(t--){
		string s;
		int ans=inf;
		cin>>n>>k>>s;//s长度,子串长度,s
		for(int i=0;i<n-k+1;i++){//从i开始枚举子串
			for(int j=0;j<3;j++){//分别从R,G,B开始比较
				int change=0;
				for(int pos=0;pos<k;pos++){
					if(s[i+pos]!=rgb[(j+pos)%3])
						change++;//若不同,则改变
				}
				ans=min(ans,change);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
