class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1,mp2;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(mp1.count(s[i]))
            {
                if(mp1[s[i]]!=t[i])
                return false;
            }
            else if(mp2.count(t[i]))
            {
                if(mp2[t[i]]!=s[i])
                return false;
            }
            else
            {
                mp1[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }
        }
        return true;
    }
};
