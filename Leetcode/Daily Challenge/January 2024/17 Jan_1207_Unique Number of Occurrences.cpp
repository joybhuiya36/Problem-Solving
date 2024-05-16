class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int f[2001]={0};
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            f[arr[i]+1000]++;
        }
        unordered_set<int> s;
        for(int i=0;i<2001;i++)
        {
            if(f[i]==0)
            continue;
            if(s.count(f[i]))
            return false;
            s.insert(f[i]);
        }
        return true;
    }
};
