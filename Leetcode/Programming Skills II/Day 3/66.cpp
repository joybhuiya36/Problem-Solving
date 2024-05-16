class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> n(digits.size()+1);
        n[0]=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]+1>9)
            {
                digits[i]=0;
                n[i+1]=0;
            }
            else
            {
                digits[i]+=1;
                // n[i+1]=digits[i]+1;
                break;
            }
        }
        if(digits[0]==0)
        return n;
        else
        return digits;
    }
};
