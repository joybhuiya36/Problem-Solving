//Test Case:
//"2"
//"3"
//"123"
//"456"
//"224847843544124"
//"377709987978"
//"2245"
//"45"
//"455"
//"50"
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n1=num1.length(), n2=num2.length();
        int res=0,res2=0,product,sum,idx=0,k;
        string s,ans;
        for(int i=n2-1;i>=0;i--)
        {
            for(int j=n1-1;j>=0;j--)
            {
                product=(num1[j]-'0')*(num2[i]-'0')+res;
                s+='0'+(product%10);
                res=product/10;
            }
            if(res!=0)
            s+='0'+res;
            
            k=idx;
            while(k<ans.length())		// summing s to previous ans
            {
                sum=(ans[k]-'0')+(s[k-idx]-'0')+res2;
                ans[k]='0'+(sum%10);
                res2=sum/10;
                k++;
            }
            while(k-idx<s.length())		//when s is larger than ans len
            {
                sum=((s[k-idx]-'0')+res2);
                ans+='0'+(sum%10);
                res2=sum/10;
                k++;
            }
            if(res2!=0)
            ans+='0'+res2;
            idx++;
            
            s="";
            res=0;
            res2=0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
