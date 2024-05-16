class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> mp,visited;
        for(int i=0;i<bank.size();i++)
        mp.insert(bank[i]);
        queue<string> q;
        q.push(startGene);
        int n,count=0;
        string s,str;
        while(!q.empty())
        {
            n=q.size();
            while(n--)
            {
                s=q.front();
                q.pop();
                if(s==endGene)
                return count;
                for(char c:"ACGT")
                {
                    for(int i=0;i<s.length();i++)
                    {
                        str=s;
                        str[i]=c;
                        if(!visited.count(str) && mp.count(str))
                        {
                            q.push(str);
                            visited.insert(str);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
