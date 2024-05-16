class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1=word1.length(), len2=word2.length(),t;
        string merge;
        if(len1>=len2)
        t=len1;
        else t=len2;
        int i=0,j=0;
        while(t--)
        {
            if(i<len1 && j<len2)
            {
                merge+=word1[i];
                merge+=word2[j];
                i++; j++;
            }
            else if(i<len1)
            {
                merge+=word1[i];
                i++;
            }
            else if(j<len2)
            {
                merge+=word2[j];
                j++;
            }
        }
        return merge;
    }
};
