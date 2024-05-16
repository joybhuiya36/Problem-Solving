class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<string,char> mp;
        vector<bool> visit(26,false);
        int m=p.size(), n=s.size();
        int i=0,j=0;
        for(;i<m && j<n;i++,j++)
        {
            string w;
            while(j<n && s[j]!=' ')
            w+=s[j++];
            if(mp.count(w))
            {
                if(mp[w]!=p[i])
                return false;
            }
            else
            {
                if(visit[p[i]-'a'])
                return false;
                visit[p[i]-'a']=true;
                mp[w]=p[i];
            }
        }
        if(i<m || j<n)
        return false;
        return true;
    }
};
