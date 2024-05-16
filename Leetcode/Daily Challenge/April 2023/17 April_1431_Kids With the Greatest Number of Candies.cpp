class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=candies[0];
        vector<bool> v;
        for(int i=1;i<candies.size();i++)
        if(candies[i]>mx)
        mx=candies[i];
        for(int i:candies)
        {
            if(i+extraCandies>=mx)
            v.push_back(true);
            else v.push_back(false);
        }
        return v;
    }
};
