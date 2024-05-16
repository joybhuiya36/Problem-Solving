class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size()-1;
        int d;
        while(n>=0)
        {
            d=num[n]-'0';
            if(d%2==1)
            return num.substr(0,n+1);
            n--;
        }
        return "";
    }
};
