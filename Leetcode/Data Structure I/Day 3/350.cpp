#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int,int> mp;
        int n1=nums1.size(), n2=nums2.size();
        for(int i=0;i<n1;i++)
        {
            mp[nums1[i]]++;
        }
        for(int i=0;i<n2;i++)
        {
            if(mp[nums2[i]]>0)
            {
                v.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return v;
    }
};

int main()
{
	map<int,int> mp;
	mp[2]++; mp[2]++;
	cout<<mp[2];
	return 0;
}
