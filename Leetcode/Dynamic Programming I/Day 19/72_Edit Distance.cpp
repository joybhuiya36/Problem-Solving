//DP
//Space Optimization
class Solution {
public:
    int minDistance(string w1, string w2) {
        int m=w1.length(), n=w2.length();
        vector<int> cur(n+1,0), pre(n+1);
        for(int i=0;i<=n;i++)
        pre[i]=i;
        for(int i=1;i<=m;i++)
        {
            cur[0]=i;
            for(int j=1;j<=n;j++)
            {
                if(w1[i-1]==w2[j-1])
                cur[j]=pre[j-1];
                else
                cur[j]=1+min(cur[j-1], min(pre[j],pre[j-1]));
            }
            pre=cur;
        }
        return pre[n];
    }
};
//Memorization
class Solution
{
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2)
    {
        memo.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return minDistanceRecur(word1, word2, word1.size(), word2.size());
    }

    int minDistanceRecur(string &word1, string &word2, int word1Index, int word2Index)
    {
        if (word1Index == 0)
        return word2Index;
        if (word2Index == 0)
        return word1Index;
        if (memo[word1Index][word2Index] != -1)
        return memo[word1Index][word2Index];
        int minEditDistance = 0;
        if (word1[word1Index - 1] == word2[word2Index - 1])
        minEditDistance = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        else
        {
            int insertOperation = minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            minEditDistance = min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
};

//Tabulation
class Solution
{
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2)
    {
        int word1Length = word1.size();
        int word2Length = word2.size();
        if(word1Length == 0)
        return word2Length;
        if(word2Length == 0)
        return word1Length;
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int word1Index = 1; word1Index <= word1Length; word1Index++)
        dp[word1Index][0] = word1Index;
        for (int word2Index = 1; word2Index <= word2Length; word2Index++)
        dp[0][word2Index] = word2Index;
        for (int word1Index = 1; word1Index <= word1Length; word1Index++)
        {
            for (int word2Index = 1; word2Index <= word2Length; word2Index++)
            {
                if (word2[word2Index - 1] == word1[word1Index - 1])
                dp[word1Index][word2Index] = dp[word1Index - 1][word2Index - 1];
                else
                {
                    dp[word1Index][word2Index] = min(dp[word1Index - 1][word2Index],
                                                     min(dp[word1Index][word2Index - 1],
                                                         dp[word1Index - 1][word2Index - 1])) +
                                                 1;
                }
            }
        }

        return dp[word1Length][word2Length];
    }
};
