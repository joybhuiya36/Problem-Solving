class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1=s.length(), n2= t.length();
        string a,b;
        int i=0,j=0;
        while(i<n1 || j<n2)
        {
            if(i<n1)
            {
                if(s[i]=='#')
                {
                    if(a.length())
                    a.pop_back();
                }
                else a.push_back(s[i]);
                i++;   
            }
            else if(j<n2)
            {
                if(t[j]=='#')
            	{
                	if(b.length())
                	b.pop_back();
            	}
            	else b.push_back(t[j]);
                j++;
        	}

        }
        if(a.length()!=b.length())
        return false;
        i=0;
        while(i<a.length())
        {
            if(a[i]!=b[i])
            return false;
            i++;
        }
        return true;
    }
};
