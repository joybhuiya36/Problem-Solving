class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int sum=0;
        for(string &s:op)
        {
            if(s[0]=='X')
            {
                if(s[1]=='+')
                sum++;
                else sum--;
            }
            else
            {
                if(s[1]=='+')
                sum++;
                else sum--;
            }
        }
        return sum;
    }
};
