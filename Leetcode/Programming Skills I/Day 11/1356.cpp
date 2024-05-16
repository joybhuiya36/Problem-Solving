#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
    	int count=0,n;
       vector<vector<int> > v(14);
	    for(int i=0;i<arr.size();i++)
	    {
	    	count=0;
	    	n=arr[i];
	    	while(n)
	    	{
	    		n&=n-1;
	    		count++;
			}
			v[count].push_back(arr[i]);
		}
		for(int i=0;i<v.size();i++)
		{
			if(v[i].size()!=0)
			sort(v[i].begin(),v[i].end());
		}
//		for(int i=0;i<v.size();i++)
//		{
//			cout<<i<<" ";
//			for(int j=0;j<v[i].size();j++)
//			cout<<v[i][j]<<" ";
//			cout<<endl;
//		}
		int k=0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i].size()!=0)
			{
				for(int j=0;j<v[i].size();j++)
				{
					arr[k]=v[i][j];
					k++;
				}
			}
		}
		return arr;
    }
};

int main()
{
	Solution ob;
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(5);
	arr.push_back(4);
	arr.push_back(3);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(8);
	for(int i=0;i<arr.size();i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	ob.sortByBits(arr);
	for(int i=0;i<arr.size();i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}

//via sort compare function
//class Solution {
//public:
//    static bool compareFunc(const int& a, const int& b)
//    {
//        int a_bit_counts = bitset<32>(a).count();
//        int b_bit_counts = bitset<32>(b).count();
//        bool use_cardinality = a_bit_counts != b_bit_counts;
//        if(use_cardinality)
//            return a_bit_counts < b_bit_counts;
//        return a<b;
//    }   
//
//    vector<int> sortByBits(vector<int> nums) {
//        sort(nums.begin(), nums.end(), compareFunc);
//        return nums;
//    }
//};
