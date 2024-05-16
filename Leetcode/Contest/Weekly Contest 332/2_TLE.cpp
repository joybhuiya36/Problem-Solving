#include<bits/stdc++.h>
using namespace std;
//6355. Count the Number of Fair Pairs
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int m,lt,ut,l,r=nums.size()-1,count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
        	int flag=0;
        	lt=lower-nums[i];
        	ut=upper-nums[i];
        	l=i+1;
        	while(l<=r)
        	{
        		int mid=(l+r)/2;
        		if(nums[mid]>=lt && nums[mid]<=ut)
        		{
        			cout<<"i "<<i<<" mid "<<mid<<endl;
        			flag=1;
        			count++;
        			m=mid;
        			break;
				}
				else if(nums[mid]>ut)
				r=mid-1;
				else if(nums[mid]<lt)
				l=mid+1;
			}
			int a = m-1; int b=m+1;
			if(a>i && flag==1)
			{
				while(nums[a]>=lt)
				{
					cout<<"loop 1 "<<a<<endl;
					count++;
					a--;
					if(a<=i)
					break;
				}
			}
			if(b<nums.size() && flag==1)
			{
				while(nums[b]<=ut)
				{
					cout<<"loop 2 "<<b<<endl;
					count++;
					b++;
					if(b>=nums.size())
					break;
				}
			
			}
		}
		return count;
    }
};

int main()
{
	Solution ob;
	vector<int> v;
	v.push_back(0);  //[0,1,7,4,4,5] [1,7,9,2,5], [-1,0]
	v.push_back(0);		//3 6			11 11		1 1
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	int l=0, u=0;
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
