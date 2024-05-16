//One_Pass
class Solution {
public:
	int check(char &c)
    {
        return c=='T'? 1:0;
    }
    int maxConsecutiveAnswers(string s, int k) {
        int l=0,r=0,n=s.length(),ans=0;
        int mp[2]={0};
        while(r<n)
        {
            mp[check(s[r])]++;
            while(min(mp[1],mp[0])>k)
            {
                mp[check(s[l])]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
//Two_Pass
class Solution {
public:
    int maxConsecutiveAnswers(string s, int K) {
        int n=s.length(), l=0, r=0, ans=0,k=K;
        while(r<n)
        {
            if(s[r]!='T')
            k--;
            while(k<0)
            {
                if(s[l]=='F')
                k++;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        l=0; r=0; k=K;
        while(r<n)
        {
            if(s[r]!='F')
            k--;
            while(k<0)
            {
                if(s[l]=='T')
                k++;
                l++;
            }
            
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
