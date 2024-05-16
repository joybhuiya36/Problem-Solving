class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int res=0;
        int n;
        int n1=num1.length(), n2=num2.length();
        if(n1>=n2)
        n=n1;
        else n=n2;
        int a=n1-1, b=n2-1;
        for(int i=0; i<n; i++)
        {
            if(a>=0)
            res+=num1[a--]-'0';
            if(b>=0)
            res+=num2[b--]-'0';
            ans+='0'+(res%10);
            res/=10;
        }
        if(res!=0)
        ans+='0'+res;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
