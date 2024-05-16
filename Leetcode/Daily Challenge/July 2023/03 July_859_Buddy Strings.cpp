class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int m=s.length(), n=goal.length(),diff=0;
        vector<int> p;
        if(m!=n) return false;
        int alph[26]={0}, flag=0;
        for(int i=0;i<m;i++)
        {
            if(flag==0)
            {
                if(++alph[s[i]-'a']>1)
                flag=1;
            }
            if(s[i]!=goal[i])
            {
                diff++;
                if(diff>2) return false;
                p.push_back(i);
            }
        }
        if(diff==0)
        {
            if(flag==1)
            return true;
            else return false;
        }
        else if(diff==2)
        {
            if(s[p[0]]==goal[p[1]] && s[p[1]]==goal[p[0]])
            return true;
            else
            return false;
        }
        else return false;
    }
};
