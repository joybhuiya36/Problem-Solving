class Solution {
public:
    string simplifyPath(string path) {
        string s="/";
        string dot="";
        int n=path.length();
        for(int i=1;i<n;i++)
        {
            if(path[i]=='/')
            {
                if(s.back()!='/')
                s+='/';
                else continue;
            }
            else if(path[i]=='.')
            {
                while(i<path.length() && path[i]=='.')
                {
                    dot+='.';
                    i++;
                }
                
                if(i<path.length() && path[i]!='/')
                {
                    s+=dot;
                    while(i<path.length() && path[i]!='/')
                    s+=path[i++];
                }
                else if(dot.length()==2)
                {
                    if(s.length()>1)
                    {
                        s.pop_back();
                        while(s.back()!='/')
                        s.pop_back();
                    }
                }
                else if(dot.length()>2)
                {
                    s+=dot;
                }
                i--;
                dot="";
            }
            else
            {
                while(i<path.length() && path[i]!='/')
                s+=path[i++];
                i--;
            }
        }
        if(s.length()>1 && s.back()=='/')
        s.pop_back();
        return s;
    }
};
