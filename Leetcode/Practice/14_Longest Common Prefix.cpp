//My Solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int n=strs.size(),j=0;
        while(1)
        {
            if(strs[0].size()==j)
            return s;
            for(int i=1;i<n;i++)
            {
                if(strs[i].size()==j || strs[i-1][j]!=strs[i][j])
                return s;
            }
            s+=strs[0][j];
            j++;
        }
        return s;
    }
};
//Sort
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string p=strs[0];
        string q=strs[n-1];
        string ans="";
        for(int i=0;i<p.size();i++)
        {
            if(p[i]==q[i])
            {
                ans = ans + p[i];
            }
            else   
                break;
        }
        return ans;
    }
};
