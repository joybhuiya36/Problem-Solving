class Solution {
public:
int m;
    void reverse(string &s)
    {
        m=s.length();
        for(int i=0;i<m/2;i++)
        swap(s[i],s[m-1-i]);
    }
    string reverseWords(string s) {
        string str,ans;
        int n=s.length();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
            str+=s[i];
            else
            {
                if(str.length()==0) continue;
                else
                {
                    reverse(str);
                    ans+=str+" ";
                    str="";
                }
            }
        }
        if(str.length()==0) ans.pop_back();
        else
        {
            reverse(str);
            ans+=str;
        }
        return ans;
    }
};
