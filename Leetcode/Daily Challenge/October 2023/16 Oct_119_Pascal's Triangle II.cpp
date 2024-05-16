class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<int> pre(n),cur(n);
        pre[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j==0||j==i)
                cur[j]=1;
                else
                cur[j]=pre[j]+pre[j-1];
            }
            pre=cur;
        }
        return pre;
    }
};
