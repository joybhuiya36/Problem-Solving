class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2==1)
        return false;
        stack <char> stk;
        if(s[0]=='(' || s[0]=='{' || s[0]=='[')
        stk.push(s[0]);
        else return false;
        for(int i=1;i<s.length();i++)
        {
            if(!stk.empty() && ((stk.top()=='(' && s[i]==')')||(stk.top()=='{' && s[i]=='}')||(stk.top()=='[' && s[i]==']')))
            stk.pop();
            else if(!stk.empty() && ((stk.top()=='(' && (s[i]=='}'||s[i]==']')) || (stk.top()=='{' && (s[i]==')'||s[i]==']')) || (stk.top()=='[' && (s[i]==')'||s[i]=='}'))))
            return false;
            else
            stk.push(s[i]);
        }
        if(stk.empty())
        return true;
        else return false;
    }
};
