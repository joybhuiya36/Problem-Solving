class Solution {
public:
    string createLine(int i, int j, int each, int extra, vector<string> &words, int &maxWidth)
    {
        string s;
        
        for(int k=i;k<j;k++)
        {
            s+=words[k];
            if(k==j-1) continue;
            for(int x=0;x<each;x++)
            s+=" ";
            if(extra>0)
            {
                s+=" ";
                extra--;
            }
        }
        while(s.length()<maxWidth)
        s+=" ";
        return s;

    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<string> v;
        int i=0;
        while(i<n)
        {
            int ltrs=words[i].length(),whitespace=0,j=i+1;
            while(j<n && words[j].length()+1+ltrs+whitespace<=maxWidth)
            {
                ltrs+=words[j].length();
                whitespace++;
                j++;
            }
            int eachSpace=whitespace==0? 0:(maxWidth-ltrs)/whitespace;
            int extraSpace=whitespace==0? 0:(maxWidth-ltrs)%whitespace;
            if(j==n)
            {
                eachSpace=1;
                extraSpace=0;
            }
            v.push_back(createLine(i,j,eachSpace,extraSpace,words,maxWidth));
            i=j;
        }
        return v;
    }
};
