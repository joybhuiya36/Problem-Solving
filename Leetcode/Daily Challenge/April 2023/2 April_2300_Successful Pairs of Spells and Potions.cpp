class Solution {
public:
    int b_search(long long i, vector<int>& ptn, long long &scs)
    {
        int l=0, r=ptn.size()-1;
        while(l<=r)
        {
            int mid=((r-l)/2)+l;
            if(ptn[mid]*i>=scs)
            r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spl, vector<int>& ptn, long long scs) {
        sort(ptn.begin(),ptn.end());
        vector<int>v;
        for(int &i:spl)
        {
            int idx=b_search(i,ptn,scs);
            v.push_back(ptn.size()-idx);
        }
        return v;
    }
};
