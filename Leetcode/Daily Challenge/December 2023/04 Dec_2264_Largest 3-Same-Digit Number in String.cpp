class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size(), cnt=1, tmp=-1;
        string ans;
        for(int i=1;i<n;i++)
        {
            if(num[i-1]==num[i])
            cnt++;
            else cnt=1;
            if(cnt==3)
            {
                tmp=max(tmp,num[i]-'0');
            }
        }
        for(int i=0;i<3;i++)
        ans+=(tmp+'0');
        return tmp==-1? "":ans; 
    }
};
