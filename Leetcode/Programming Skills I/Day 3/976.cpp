#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int nums[n], perimeter=0;
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	sort(nums,nums+n,greater<int>());
	for(int i=0;i<n;i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	cout<<"n "<<n<<endl;
    for(int i=0;i<n-2;i++)
	{
		cout<<"i "<<i<<endl;
		if(nums[i]==nums[i+1]+nums[i+2])
		continue;
		else if(nums[i]<nums[i+1]+nums[i+2])
		{
			cout<<"2nd if"<<endl;
			perimeter= nums[i]+nums[i+1]+nums[i+2];
			break;
		}	
	}
	cout<<perimeter;
	return 0;
}

//class Solution {
//public:
//    int largestPerimeter(vector<int>& nums) {
//
//    int n=nums.size();
//    sort(nums.begin(), nums.end(), greater<int>());
//    for(int i=0;i<n-2;i++)
//        if(nums[i]<nums[i+1]+nums[i+2])
//		return nums[i]+nums[i+1]+nums[i+2];
//	return 0;
//    }
//};
