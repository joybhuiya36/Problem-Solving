class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int len=s.length();
        if(len==1) return -1;
        stack<int> stk;
        vector<int>v(len,-1);
        for(int i=len-1;i>=0;i--)
        {
            while(!stk.empty() && s[i]<s[stk.top()])
            {
                v[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        int mx=-1,ind;
        for(int i=len-1;i>=0;i--)
        {
            if(v[i]>mx)
            {
                mx=v[i];
                ind=i;
            }
            
        }
        if(mx==-1) return mx;
        swap(s[ind],s[mx]);
        sort(s.begin()+mx+1,s.end());
        try
        {
            int num = stoi(s);
        }
    	catch (const out_of_range& e)
        {
            return -1;
        }

        return stoi(s);
    }
};
