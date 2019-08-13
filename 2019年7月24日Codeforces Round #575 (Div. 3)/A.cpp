#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long t,a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		long long x=min(min(a,b),c),z=max(max(a,b),c),y=a+b+c-x-z,maxi=0;
        if(y-x>z)
			cout<<x+z<<endl;
		else
			cout<<y+(long long)((z-(y-x))/2)<<endl;
	}
	return 0;
}
