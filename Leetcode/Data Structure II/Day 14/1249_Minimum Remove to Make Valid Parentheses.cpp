//One stack with dot(.) approach
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            st.push(i);
            else if(s[i]==')')
            {
                if(st.empty())
                s[i]='.';
                else
                st.pop();
            }
        }
        while(!st.empty())
        {
            s[st.top()]='.';
            st.pop();
        }
        string str;
        for(int i=0;i<s.size();i++)
        if(s[i]!='.')
        str+=s[i];
        return str;
    }
};
//My first Solution with two stack
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st, st2;
        int brkt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            brkt++;
            else if(s[i]==')')
            brkt--;
            if(brkt>=0)
            st.push(s[i]);
            else
            brkt=0;
        }
        brkt=0;
        char ch;
        while(!st.empty())
        {
            ch=st.top();
            if(ch==')')
            brkt++;
            else if(ch=='(')
            brkt--;
            if(brkt>=0)
            st2.push(ch);
            else
            brkt=0;
            st.pop();
        }
        string str;
        while(!st2.empty())
        {
            str+=st2.top();
            st2.pop();
        }
        return str;
    }
};
