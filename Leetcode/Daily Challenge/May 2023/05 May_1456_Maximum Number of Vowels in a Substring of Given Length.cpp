class Solution {
public:
	bool isv(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
        else
        return false;
    }
    int maxVowels(string s, int k) {
        int i=0,v=0;
        while(i<k)
        {
            if(isv(s[i++])) v++;
        }
        if(v==k) return k;
        int l=0,mx=v;
        while(i<s.length())
        {
            if(isv(s[l])) v--;
            if(isv(s[i])) v++;
            if(v>mx) mx=v;
            if(mx==k) return k;
            l++; i++;
        }
        return mx;
    }
};
