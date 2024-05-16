class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int> st;
        int num=0,rslt=0,sign=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            continue;
            else if(isdigit(s[i]))
            {
                num=(num*10)+(s[i]-'0');
            }
            else if(s[i]=='+')
            {
                rslt+=(sign*num);
                num=0;
                sign=1;
            }
            else if(s[i]=='-')
            {
                rslt+=(sign*num);
                num=0;
                sign=-1;
            }
            else if(s[i]=='(')
            {
                st.push(rslt);
                st.push(sign);
                num=0; rslt=0; sign=1;
            }
            else if(s[i]==')')
            {
                rslt+=(sign*num);
                num=0;
                rslt*=st.top();
                st.pop();
                rslt+=st.top();
                st.pop();
            }
        }
        rslt+=(sign*num);
        return rslt;
    }
};
