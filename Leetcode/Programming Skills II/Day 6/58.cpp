class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0,mx=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                if(count!=0)
                mx=count;
                count=0;
            }
            else count++;
        }
        if(count!=0)
        mx=count;
        return mx;
    }
};
