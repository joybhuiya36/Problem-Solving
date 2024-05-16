class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ch, n=s.length();
        vector<pair<int,int>> mp(26,{-1,-1});
        for(int i=0;i<n;i++)
        {
            ch=s[i]-'a';
            if(mp[ch].first==-1)
            mp[ch].first=i;
            mp[ch].second=i;
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(mp[i].first==-1)
            continue;
            unordered_set<char> st;
            for(int j=mp[i].first+1;j<mp[i].second;j++)
            st.insert(s[j]);
            ans+=st.size();
        }
        return ans;
    }
};
