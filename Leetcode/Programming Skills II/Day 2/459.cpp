class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str=s+s;
        for(int i=1;i<(s.length()/2)+1;i++)
        {
            int j=i, k=0;
            while(s[k]==str[j])
            {
                j++; k++;
                if(k==s.length())
                return true;
            }
            
        }
        return false;
    }
};
