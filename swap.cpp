#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<int> nums;

    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(12);
    int j=0;
    for(int i=0;i<nums.size();i++)
    {
    	if(nums[i]!=0)
    	{
    		swap(nums[j],nums[i]);
    		
		}
	}
	    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
	return 0;
}
