//Permutation in String
class Solution {
public:
    bool checker(vector<int> &v, vector<int> &mp)
    {
        for(int i=0;i<26;i++)
        {
            if(v[i]!=mp[i])
            return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        if(n1>n2)
        return false;
        vector<int> v(26,0), mp(26,0);
        int sum=0,cup=0,ptr=0,i=0;
        for(char &c:s1)
        {
            v[c-'a']++;
            sum+=c-'a';
        }					//For & While works can be done together
        while(i<n1)
        {
            mp[s2[i]-'a']++;
            cup+=s2[i++]-'a';
        }
        if(sum==cup && checker(v,mp)) return true;
        while(i<n2)
        {
            mp[s2[ptr]-'a']--;
            cup-=s2[ptr++]-'a';
            mp[s2[i]-'a']++;
            cup+=s2[i++]-'a';
            if(sum==cup && checker(v,mp))
            return true;
        }
        return false;
    }
};
