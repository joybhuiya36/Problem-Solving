class Solution {
public:
int f=0,s=0;
    void combi(string &v, vector<string> &ans, int &n)
    {
        if(v.length()==n*2)
        {
            ans.push_back(v);
            return;
        }
        if (f<n)
        {
            v+="(";
            f++;
            combi(v,ans,n);
            v.pop_back();
            f--;
        }
        if(f>s)
        {
            v+=")";
            s++;
            combi(v,ans,n);
            v.pop_back();
            s--;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string v;
        combi(v,ans,n);
        return ans;
    }
};
