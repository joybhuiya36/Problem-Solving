class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size(), n=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int c=0,i=0,j=0;
        while(i<m && j<n)
        {
            if(s[j]>=g[i])
            {
                c++; i++; j++;
            }
            else j++;
        }
        return c;
    }
};
