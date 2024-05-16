//DP
//Memorization
class Solution {
public:
    int stockSell(int i, bool take, vector<int> &p, vector<vector<int>> &dp, int &n)
    {
        if(i==n)
        return 0;
        if(dp[i][take]!=-1)
        return dp[i][take];
        if(take==false)
        return dp[i][take]=max(-p[i]+stockSell(i+1,true,p,dp,n),stockSell(i+1,false,p,dp,n));
        else return dp[i][take]=max(p[i]+stockSell(i+1,false,p,dp,n),stockSell(i+1,true,p,dp,n));
//   or else return dp[i][take]=p[i]+stockSell(i,false,p,dp,n);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return stockSell(0,false,prices,dp,n);
    }
};
//Tabulation
class Solution {
public:
	int maxProfit(vector<int>& p){
		int n=p.size();
		vector<vector<int>> dp(n+1,vector<int>(2,0));
		for(int i=n-1;i>=0;i--){
			for(int buy=0;buy<=1;buy++){
				int profit;
				if(buy){
					int buy=-p[i]+dp[i+1][0];
					int notbuy=dp[i+1][1];
					profit=max(buy,notbuy);
				}
				else{
					int sell= p[i]+dp[i+1][1];
					int notsell=dp[i+1][0];
					profit=max(sell,notsell);
				}
				dp[i][buy]=profit;
			}
		}
		return dp[0][1];
	}
};
//or My Solution(same as previous)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int take=0;take<2;take++)
            {
                if(take==0)
                dp[i][take]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
                else dp[i][take]=max(prices[i]+dp[i+1][0],dp[i+1][1]);
            }
        }
        return dp[0][0];
    }
};
//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<int> cur(2,0);
        vector<int> next(2,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int take=0;take<2;take++)
            {
                if(take==0)
                cur[take]=max(-prices[i]+next[1],next[0]);
                else cur[take]=max(prices[i]+next[0],next[1]);
            }
            next=cur;
        }
        return cur[0];
    }
};
//One pass (Greedy)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int l=prices[0], ans=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]>l)
            {
                ans+=prices[i]-l;
                l=prices[i];
            }
            else
            l=min(l,prices[i]);
        }
        return ans;
    }
};
//or My Solution(same as previous)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]>prices[i-1])
            ans+=prices[i]-prices[i-1];
        }
        return ans;
    }
};
//Peak Valley Approach
class Solution {
    public int maxProfit(int[] prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.length - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
}
