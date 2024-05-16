//String Matching by Sliding Windows
class Solution {
public:
    int strStr(string haystack, string needle) {
        int flag=-1,k;
        for(int i=0,j=0;i<haystack.size()-needle.size()+1;i++)
        {
            j=0; flag=-1;
            if(haystack[i]==needle[j])
            {
                flag=1;
                k=i; i++; j++;
                while(j<needle.size())
                {
                    if(haystack[i]!=needle[j])
                    {
                        flag=-1;
                        break;
                    }
                    else if(haystack[i]==needle[j])
                    {
                        flag=1;
                        i++; j++;
                    }
                }
                if(flag==1) return k;
                i=k;
            }
        }
        return flag;
    }
};
//Can be solved by Rabin-Karp Algorithm (Single Hash)
//at first making the hash sum of needle, then do matching with haystack 1/1, if the hash sum matches, then do matching with each character
