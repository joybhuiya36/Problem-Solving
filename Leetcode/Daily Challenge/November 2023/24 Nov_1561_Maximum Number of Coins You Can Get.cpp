class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int l=1, r=piles.size()-1, mx=0;
        while(l<r)
        {
            mx+=piles[l];
            l+=2; r--;
        }
        return mx;
    }
};
