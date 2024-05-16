class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.length();
        int n2=num2.length();
        if((n1==1 && num1[0]=='0') || n2==1 && num2[0]=='0')
        return to_string(0);
        string str;
        for(int i=0;i<n1+n2;i++)
        str+='0';
        for(int i=n2-1;i>=0;i--)
        {
            int res=0;
            int k=n2-1-i;
            for(int j=n1-1;j>=0;j--)
            {
                int a= num1[j]-'0';
                int b= num2[i]-'0';
                int prd=a*b+res;
                res=prd/10;
                int rest=prd%10;
                int d_sum=rest+(str[k]-'0');
                int res2=d_sum%10;
                str[k]=to_string(res2)[0];
                res+=d_sum/10;
                k++;
            }
            str[k]=to_string(res+(str[k]-'0'))[0];
        }
        int len=str.length()-1;
        while(str[len]=='0')
        {
        str.erase(len,1);
        len--;
        }
        reverse(str.begin(),str.end());
        cout<<str;
        return str;
    }
};
