class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        int sum=pref[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=sum^pref[i];
            sum^=pref[i];
        }
        return pref;
    }
};
