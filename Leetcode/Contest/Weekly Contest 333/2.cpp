#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,pw,min1,min2,mn,count=0;
	cin>>n;
	mn=n;
	while(mn)
	{
		pw=log2(mn);
//		cout<<pw<<endl;
		min1=(pow(2,pw+1))-mn;
		min2=mn-(pow(2,pw));
		mn=min(min1,min2);
//		cout<<mn<<endl;
		count++;
	}
	cout<<count;
//	Solution ob;
	return 0;
}
