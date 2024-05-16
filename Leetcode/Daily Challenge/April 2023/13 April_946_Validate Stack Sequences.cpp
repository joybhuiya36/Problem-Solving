class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j=0;
        for(int i=0;i<pushed.size();i++)
        {
            stk.push(pushed[i]);
            while(j<popped.size() && stk.size()>0 && popped[j]==stk.top())
            {
                stk.pop();
                j++;
            }
        }
        if(stk.empty()) //return j==.pushed.size();
        return true;
        return false;
    }
};
