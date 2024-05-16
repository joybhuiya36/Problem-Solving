class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length(), n=t.length();
        if(m<n) return "";
        unordered_map<char,int> mp;
        for(char &c:t)
        mp[c]++;
        int i=0,j=0,minWindow=INT_MAX, idx;
        while(j<m)
        {
            if(mp[s[j]]>0)
            {
                mp[s[j]]--;
                n--;
            }
            else mp[s[j]]--;
            while(n==0)
            {
                if(minWindow>j-i+1)
                {
                    minWindow=j-i+1;
                    idx=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                n++;
                i++;
            }
            j++;
        }
        return minWindow==INT_MAX? "":s.substr(idx,minWindow);
    }
};
