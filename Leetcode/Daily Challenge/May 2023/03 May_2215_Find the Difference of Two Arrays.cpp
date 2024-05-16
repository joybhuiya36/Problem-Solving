class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        vector<vector<int>> ans(2);
        for(int i=0;i<nums1.size();i++)
        st1.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++)
        st2.insert(nums2[i]);
        unordered_set<int> n1;
        unordered_set<int> n2;
        for(int i=0;i<nums1.size();i++)
        {
            if(!st2.count(nums1[i]))
            n1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(!st1.count(nums2[i]))
            n2.insert(nums2[i]);
        }
        return {vector<int>(n1.begin(),n1.end()),vector<int>(n2.begin(),n2.end())};
    }
};
//Space Optimized Solution
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2,vector<int>{});
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                ++i,++j;
            }else if(nums1[i] < nums2[j]){   
                if(i == 0 || nums1[i] != nums1[i-1])ans[0].push_back(nums1[i]);
                ++i;
            }
            else if(nums1[i] > nums2[j]){
                if(j == 0 || nums2[j] != nums2[j-1])ans[1].push_back(nums2[j]);
                ++j;
            }
        }
        while(i != nums1.size()){
            if(i == 0 || nums1[i] != nums1[i-1])ans[0].push_back(nums1[i]);
            ++i;
        }
        while(j != nums2.size()){
            if(j == 0 || nums2[j] != nums2[j-1])ans[1].push_back(nums2[j]);
            ++j;
        }

        return ans;
    }
};
