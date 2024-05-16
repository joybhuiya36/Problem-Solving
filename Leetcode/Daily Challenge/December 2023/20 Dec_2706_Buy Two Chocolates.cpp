class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int f=101,s=101;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            if(prices[i]<f)
            {
                s=f;
                f=prices[i];
            }
            else if(prices[i]<s)
            s=prices[i];
        }
        f+=s;
        return money>=f? money-f: money;
    }
};
