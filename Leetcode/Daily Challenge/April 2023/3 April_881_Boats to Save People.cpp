class Solution {
public:
    int numRescueBoats(vector<int>& ppl, int limit) {
        sort(ppl.begin(),ppl.end(),greater<int>());
        int l=0, r=ppl.size()-1, boat=0;
        while(l<=r)
        {
            if(l==r)
            {
                l++;
                boat++;
            }
            else if(ppl[l]+ppl[l+1]<=limit)
            {
                boat++;
                l+=2;
            }
            else if(ppl[l]+ppl[r]<=limit)
            {
                boat++;
                l++;
                r--;
            }
            else
            {
                boat++;
                l++;
            }
        }
        return boat;
    }
};
