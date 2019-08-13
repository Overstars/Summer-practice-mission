#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[200005],part[200005],n,k,flag;
void dfs(int left,int right,int cnt)//分成k组,
{//以left开头(包括),right结尾(不包括),从1计数第cnt组
	if(cnt==k){
		if((arr[n]-arr[left-1])%2==1){
			if(flag==0){
				flag=1;
				printf("YES\n");
			}
			part[cnt]=left;
			printf("%d",part[1]);
			for(int i=2;i<=k;i++)
				printf(" %d",part[i]);
		}
		return;
	}
	if(cnt>0&&(arr[right-1]-arr[left-1])%2==0)
		return;
	if(cnt>=k||left>right||left<0||left>n||right>n)
		return;
	part[cnt]=left;
	if(cnt==1)
		for(int i=1;i<n-1;i++)
			for(int j=i+1;j<n;j++){
				if((arr[j-1]-arr[i-1])%2==1&&(arr[i-1]%2==1))
					dfs(i,j,2);//搜索第二组
			}
	else
		for(int i=right+1;i<n;i++){//下一部分的结尾
			if((arr[i-1]-arr[right-1])%2==1)
				dfs(right,i,cnt+1);
		}
}
int main()
{
	int t,temp;
	cin>>t;
	while(t--){
		flag=0;
		part[0]=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			scanf("%d",&temp);
			arr[i]=arr[i-1]+temp;//前缀和
		}
		if(k==1){
			if(arr[n]%2==1){
				printf("YES\n1\n");
			}
			else
				cout<<"NO"<<endl;
			continue;
		}
		dfs(1,2,1);
		if(flag==0)
			cout<<"NO"<<endl;
	}
	return 0;
}
