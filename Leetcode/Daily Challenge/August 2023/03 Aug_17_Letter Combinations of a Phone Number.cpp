class Solution {
public:
vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void combi(int idx, string &d, string &v, vector<string> &ans, int &n)
    {
        if(v.length()==n)
        {
            ans.push_back(v);
            return;
        }
        if(idx==d.length())
        return;
        for(int i=idx;i<d.length();i++)
        {
            string str=map[d[i]-'0'];
            for(int j=0;j<str.length();j++)
            {
                v+=str[j];
                combi(i+1,d,v,ans,n);
                v.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n=digits.length();
        if(n==0) return ans;
        string v;
        combi(0,digits,v,ans,n);
        return ans;
    }
};
