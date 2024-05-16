#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size(),l,r,mid,rm;
        vector< pair<int,int> > v(n);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            v[i].first=nums[i];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            rm=target-v[i].first;
            l=i+1; r=n-1;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(rm==v[mid].first)
                {
                	//cout<<"1st loop "<<mid<<endl;
                    ans.push_back(v[i].second);
                    ans.push_back(v[mid].second);
                    //ans[0]=v[i].second;
                    //ans[1]=v[mid].second;
                    return ans;
                }
                else if(rm<v[mid].first)
                {
                	r=mid-1;
                	//cout<<"2nd loop "<<mid<<endl;
				}
                else
                {
                l=mid+1;
                //cout<<"3rd loop "<<mid<<endl;
				}
            }
        }
        return ans;
    }
};

int main()
{
	vector<int> v;	//[2,7,11,15] 9		[3,2,4] 6
	v.push_back(3);
	v.push_back(3);
//	v.push_back(4);
//	v.push_back(15);
	int t=6;
	Solution ob;
	for(int i=0;i<2;i++)
	cout<<ob.twoSum(v,t)[i]<<" ";
	return 0;
}
//O(n) by mapping+finding
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        int n = nums.size();
//        unordered_map<int, int> mp;
//        vector<int> ans;
//        for (int i = 0; i < n; i++) {
//            int complement = target - nums[i];
//            if (mp.count(complement)) {
//                ans.push_back(mp[complement]);
//                ans.push_back(i);
//                return ans;
//            }
//            mp[nums[i]] = i;
//        }
//        return ans;
//    }
//};

