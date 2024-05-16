class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.length(), len=words.size(), m=words[0].size();
        if(n<len*m) return {};
        vector<int> ans;
        unordered_map<string,int> st;
        for(auto &w : words)
        st[w]++;
        string str;
        int j, total, count;
        for(int i=0;i<=n-m*len;i++)
        {
            unordered_map<string, int> mp;
            j=i; total=0;
            while(j<=n-m)
            {
                str=s.substr(j,m);
                if(st.count(str))
                {
                    count=++mp[str];
                    if(count>st[str])
                    break;
                    total++;
                }
                else break;
                j+=m;
                if(total==len)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
