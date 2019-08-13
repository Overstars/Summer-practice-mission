#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[200010];
int main()
{
	int t,i,n,k,odd;
	cin>>t;
	while(t--){
		cin>>n>>k;
		odd=0;
		for(i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			if(arr[i]%2==1)
				odd++;
		}
		if(odd>=k&&(odd-k+1)%2==1){
			puts("YES");
			int cnt=0;//记录输出的分组
			for(i=1;i<n;i++){
				if(cnt==k-1)
					break;
				if(arr[i]%2==1){
					printf("%d ",i);
					cnt++;
				}
			}
			printf("%d\n",n);
		}
		else
			puts("NO");
	}
	return 0;
}
