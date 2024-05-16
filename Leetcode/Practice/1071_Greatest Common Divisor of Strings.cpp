class Solution {
public:
    bool check(string &s1, string &s2, int &n)
    {
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            return false;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int m=str1.length(), n=str2.length();
        string temp;
        if(m<n)
        {
            swap(str1,str2);
            swap(m,n);
        }
        while(m>=n)
        {
            if(check(str1,str2,n))
            {
                str1=str1.substr(n);
                m=str1.length();
                if(m<n)
                {
                    swap(str1,str2);
                    swap(m,n);
                }
            }
            else return "";
            if(n==0) return str1;
        }
        return str1;
    }
};
