class Solution {
public:
    char finder(char c)
    {
        switch(c)
        {
            case ')':
            return '(';
            case '}':
            return '{';
            case ']':
            return '[';
        }
        return '0';
    }
    bool isValid(string s) {
        int n=s.length();
        if(n%2==1) return false;
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
            else
            {
                if(st.empty() || finder(s[i])!=st.top())
                return false;
                st.pop();
            }
        }
        if(st.empty())
        return true;
        else return false;
    }
};
