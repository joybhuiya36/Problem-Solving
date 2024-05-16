class Solution {
public:
    int maximumWealth(vector<vector<int>>& acc) {
        int m= acc.size();
        int sum,wealth=0;
        for(int i=0;i<m;i++)
        {
            sum=0;
            for(int j=0;j<acc[i].size();j++)
            {
               sum+=acc[i][j];
            }
            if(sum>wealth)
            wealth=sum;
        }
        return wealth;
    }
};

//class Solution {
//public:
//    int maximumWealth(vector<vector<int>>& accounts) {
//    	
//    }
//};
