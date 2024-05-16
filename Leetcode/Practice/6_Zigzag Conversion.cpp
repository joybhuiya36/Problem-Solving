class Solution {
public:
    string convert(string s, int nr) {
        if(nr==1) return s;
        int flag=0;
        vector<string> v(nr);
        int n=s.length(),i=0,r=0;
        while(i<n)
        {
            if(flag==0)
            {
                v[r].push_back(s[i++]);
                r++;
            }
            else
            {

                v[r].push_back(s[i++]);
                r--;
            }
            if(r==-1)
            {
                r=1;
                flag=0;
            }
            if(r==nr)
            {
                r=nr-2;
                flag=1;
            }
        }
        i=0;
        for(int j=0;j<nr;j++)
        {
            for(r=0;r<v[j].size();r++)
            s[i++]=v[j][r];
        }
        return s;
    }
};
