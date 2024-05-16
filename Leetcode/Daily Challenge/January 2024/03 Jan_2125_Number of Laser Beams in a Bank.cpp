class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int c, ans=0, pre=0;
        string s;
        int m;
        for(int i=0;i<n;i++)
        {
            c=0;
            s=bank[i];
            m=s.length();
            for(int j=0;j<m;j++)
            {
                if(s[j]=='1')
                c++;
            }
            if(c!=0)
            {
                ans+=pre*c;
                pre=c;
            }
        }
        return ans;
    }
};
