class Solution {
public:
vector<vector<int>> v;
    void backtrk(int i, int &n, int &k, vector<int> &temp)
    {
        if(temp.size()==k)
        {
            v.push_back(temp);
            return;
        }
        for(;i<=n;i++)
        {
            temp.push_back(i);
            backtrk(i+1,n,k,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrk(1,n,k,temp);
        return v;
    }
};
