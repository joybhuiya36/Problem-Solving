class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> mp;
        for(auto &w:wordList)
        mp[w]=false;
        if(!mp.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        mp[beginWord]=true;
        int n,len=1;
        char c;
        string cur;
        while(!q.empty())
        {
            n=q.size();
            while(n--)
            {
                cur=q.front();
                q.pop();
                if(cur==endWord)
                return len;
                for(int i=0;i<cur.size();i++)
                {
                    c=cur[i];
                    for(int j=0;j<26;j++)
                    {
                        cur[i]=('a'+j);
                        if(mp.count(cur) && mp[cur]==false)
                        {
                            q.push(cur);
                            mp[cur]=true;
                        }
                    }
                    cur[i]=c;
                }
            }
            len++;
        }
        return 0;
    }
};
