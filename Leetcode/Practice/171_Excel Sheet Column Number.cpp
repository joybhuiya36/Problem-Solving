class Solution {
public:
    int titleToNumber(string ctitle) {
        int rslt=0, d;
        for(char &c:ctitle)
        {
            d= (c-'A')+1;
            rslt=rslt*26+d;
        }
        return rslt;
    }
};
