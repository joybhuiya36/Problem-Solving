#include<bits/stdc++.h>
using namespace std;
//6355. Count the Number of Fair Pairs
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long m1,m2,lt,ut,l,r,count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
        	lt=lower-nums[i];
        	ut=upper-nums[i];
        	m1=0; m2=0;
        	l=i+1; r=nums.size()-1;
        	while(l<=r)
        	{
        		int mid=(l+r)/2;
        		if(nums[mid]>=lt)
				r=mid-1;
				else if(nums[mid]<lt)
				l=mid+1;
				m1=r;
			}
			l=i+1; r=nums.size()-1;
			while(l<=r)
        	{
        		int mid=(l+r)/2;
        		if(nums[mid]>ut)
				r=mid-1;
				else if(nums[mid]<=ut)
				l=mid+1;
				m2=r;
			}
			count+=m2-m1;
		}
		return count;
    }
};

int main()
{
	Solution ob;
	vector<int> v;
	v.push_back(0);  //[0,1,7,4,4,5] [1,7,9,2,5], [-1,0]
	v.push_back(1);		//3 6			11 11		1 1
	v.push_back(7);
	v.push_back(4);
	v.push_back(4);
	v.push_back(5);
	int l=3, u=6;
//	for(int i=0;i<6;i++)
//	cout<<v[i]<<" ";
//	cout<<endl;
	cout<<ob.countFairPairs(v,l,u);
	return 0;
}

//class Solution {
//public:
//    long long countFairPairs(vector<int>& nums, int lower, int upper) {
//        int n=nums.size();
//        long ans=0;
//        sort(nums.begin(),nums.end());
//        for(int i=0;i<n-1;i++){
//            int x=lower-nums[i],y=upper-nums[i];
//            auto it=lower_bound(nums.begin()+i+1,nums.end(),x);
//            auto gt=upper_bound(nums.begin()+i+1,nums.end(),y);
//            ans+=gt-it;
//        }
//        return ans;
//    }
//};
