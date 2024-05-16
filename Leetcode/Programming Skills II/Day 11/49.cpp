class Solution {
public:
    bool check(int ind, vector<string>& str, vector<int> &a, vector<int> &b)
    {
        for(int i=0;i<str[ind].length();i++)
        {
            int n=str[ind][i]-'a';
            if(a[n]!=b[n])
            return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> v;
        vector<int> matched(str.size(),0);
        vector<vector<int>> mp(str.size(),vector<int>(26,0));
        for(int i=0;i<str.size();i++)
        {
            for(int j=0;j<str[i].size();j++)
            {
                mp[i][str[i][j]-'a']++;
            }
        }
        int k=0;
        for(int i=0;i<str.size();i++)
        {
            if(matched[i]==1) continue;
            v.push_back({});
            v[k].push_back(str[i]);
            matched[i]=1;
            for(int j=i+1;j<str.size();j++)
            {
                if(matched[j]==0 && str[i].length()==str[j].length() && check(i,str,mp[i],mp[j]))
                {
                    matched[j]=1;
                    v[k].push_back(str[j]);
                }
            }
            k++;
        }
        return v;
    }
};

