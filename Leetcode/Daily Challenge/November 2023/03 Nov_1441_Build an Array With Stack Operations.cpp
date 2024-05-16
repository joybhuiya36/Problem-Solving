class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m=target.size();
        int p=0;
        vector<string> v;
        for(int i=0;i<m;i++)
        {
            n=target[i]-p-1;
            while(n--)
            {
                v.push_back("Push");
                v.push_back("Pop");
            }
            v.push_back("Push");
            p=target[i];
        }
        return v;
    }
};
