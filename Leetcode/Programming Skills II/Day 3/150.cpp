class Solution {
public:
    int evalRPN(vector<string>& tkn) {
        stack<int> stk;
        for(int i=0;i<tkn.size();i++)
        {
            if(tkn[i]=="+" || tkn[i]=="-" || tkn[i]=="*" || tkn[i]=="/")
            {
                int op2=stk.top();
                stk.pop();
                int op1=stk.top();
                stk.pop();
                switch(tkn[i][0])
                {
                    case '+':
                    stk.push(op1+op2);
                    break;
                    case '-':
                    stk.push(op1-op2);
                    break;
                    case '*':
                    stk.push(op1*op2);
                    break;
                    case '/':
                    stk.push(op1/op2);
                    break;
                }
            }
            else
            stk.push(stoi(tkn[i]));
        }
        return stk.top();
    }
};
