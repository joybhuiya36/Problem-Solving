class Solution {
public:
unordered_map<int,int> mp;
	bool unique(int &mask, string s)
    {
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if((mask&(1<<(s[i]-'a')))!=0)
            return false;
            mask=mask|(1<<(s[i]-'a'));
        }
        return true;
    }
	int solve(int idx, vector<string> &a, int mask, int &n)
    {
        if(idx==n)
        return 0;
        if(mp.count(mask))
        return mp[mask];
        int taken=0;
        int _mask=mask;
        if(unique(_mask,a[idx]))
        taken=a[idx].length()+solve(idx+1,a,_mask,n);
        int not_taken=solve(idx+1,a,mask,n);
        return mp[mask]=max(taken,not_taken);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        return solve(0,arr,0,n);
    }
};
