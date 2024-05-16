#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[12]={170,-368,148,672,397,-629,-788,192,170,309,-615,-237};
	sort(arr,arr+12);
	for(int i=0;i<12;i++)
	cout<<arr[i]<<" ";
	return 0;
}

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n/2;i++)
        {
            if(nums[i]==nums[i+1]||nums[n-1-i]==nums[n-2-i])
            return true;
        }
        return false;
    }
};
