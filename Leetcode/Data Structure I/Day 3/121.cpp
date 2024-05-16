#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int mx=0,mn=INT_MAX;
    for(int i=0;i<prices.size()-1;i++)
    {
		if(prices[i]<mn)
		mn=prices[i];
		else if(prices[i]-mn>mx)
		mx=prices[i]-mn;
    }
    return mx;
    }
};

int main()
{
	vector<int> v;		//[7,1,5,3,6,4]
	v.push_back(7);
	v.push_back(1);
	v.push_back(5);
	v.push_back(3);
	v.push_back(6);
	v.push_back(4);
	Solution ob;
	cout<<ob.maxProfit(v);
	return 0;
}

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int mx=;
//        for(int i=0;i<prices.size()-1;i++)
//        {
//            for(int j=i+1;j<prices.size();j++)
//            {
//                if(prices[j]-prices[i]>mx)
//                mx=prices[j]-prices[i];
//            }
//        }
//        return 0;
//    }
//};
