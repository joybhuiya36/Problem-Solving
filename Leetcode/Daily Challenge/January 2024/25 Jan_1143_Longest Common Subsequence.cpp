class Solution {
public:
    int longestCommonSubsequence(string txt1, string txt2) {
        int m=txt1.length(), n=txt2.length();
        int pre[n+1], cur[n+1];
        memset(pre,0,sizeof(pre));
        cur[n]=0;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(txt1[i]==txt2[j])
                cur[j]=1+pre[j+1];
                else cur[j]=max(pre[j],cur[j+1]);
            }
            for(int k=0;k<n+1;k++)
            pre[k]=cur[k];
        }
        return cur[0];
    }
};
