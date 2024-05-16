#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l,r;
	int n=5;
	int nums[n]={0,1,3,3,5};
	int lt;
	while(1)
	{
		cin>>lt;
		l=0; r=n-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(nums[mid]>=lt)		//For Lower_Bound if(nums[mid]>=lt)
			r=mid-1;
			else if(nums[mid]<lt)
			l=mid+1;
		}
		cout<<l<<endl;
	}
	
	return 0;
}

