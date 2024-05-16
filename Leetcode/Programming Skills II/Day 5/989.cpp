class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> n;
        int res,sum=0;
        for(int i=num.size()-1;i>=0 || k;i--)
        {
            if(k)
            {
                res=k%10;
                k/=10;
            }
            else res=0;
            if(i>=0)
            sum+=num[i]+res;
            else
            sum+=res;
            n.push_back(sum%10);
            sum/=10;
        }
        if(sum!=0)
        n.push_back(sum);
        reverse(n.begin(),n.end());
        return n;
    }
};
