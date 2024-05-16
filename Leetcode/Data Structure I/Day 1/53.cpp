#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pre(nums.size()+1);
        int mx=INT_MIN;
        pre[0]=0;
        for(int i=0;i<nums.size();i++)
        {
        	pre[i+1]=pre[i]+nums[i];
		}
		for(int i=0;i<=nums.size();i++)
		cout<<pre[i]<<" ";
		for(int i=1;i<=nums.size();i++)
		{
			for(int j=i;j<=nums.size();j++)
			{
				if(pre[j]-pre[i-1]>mx)
				mx=pre[j]-pre[i-1];
			}
		}
		return mx;
    }
};

int main()
{
	vector<int> v;
//	v.push_back(-2);		//[-2,1,-3,4,-1,2,1,-5,4]  [5,4,-1,7,8]
//	v.push_back(1);
//	v.push_back(-3);
//	v.push_back(4);
//	v.push_back(-1);
//	v.push_back(2);
//	v.push_back(1);
//	v.push_back(5);
//	v.push_back(4);
	v.push_back(-1);
//	v.push_back(7);
//	v.push_back(8);
	Solution ob;
	cout<<ob.maxSubArray(v);
	return 0;
}
