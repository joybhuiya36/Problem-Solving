class Solution {
public:
    int minOperations(string s) {
        int z=0,d=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(d!=s[i]-'0')
            z++;
            d=!d;
        }
        int o=0;
        d=1;
        for(int i=0;i<n;i++)
        {
            if(d!=s[i]-'0')
            o++;
            d=!d;
        }
        return min(z,o);
    }
};
