#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
    	
        int n=nums.size();
        int i=0;
        long long sum=0;
        while(i+1<=n/2)
        {;
            long long d=nums[n-1-i];
            long long count=1;
            while(1)
            {
                count*=10;
                d/=10;
                if(d==0) break;
            }
            sum+=(count*nums[i])+nums[n-1-i];
            i++;
        }
        if(n%2==1)
        sum+=nums[i];
        return sum;
    }
};

int main()
{
	Solution ob;
	vector<int> v;
	v.push_back(5);  //[5,14,13,8,12]
	v.push_back(14);
	v.push_back(13);
	v.push_back(8);
	v.push_back(12);
//	for(int i=0;i<5;i++)
//	cout<<v[i]<<" ";
	cout<<ob.findTheArrayConcVal(v);
	return 0;
}
