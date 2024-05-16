class Solution {
public:
    string reverseWords(string s) {
        int n=s.length(),l=0,r=0;
        while(r<n)
        {
            while(r<n && s[r]!=' ')
            r++;
            reverse(s.begin()+l,s.begin()+r);
            l=r+1; r=l;
        }
        return s;
    }
};
//or
class Solution {
public:
    string reverseWords(string s) {
        vector<int> v;
        v.push_back(-1);
        for(int i=0;i<s.length();i++)
        if(s[i]==' ')
        v.push_back(i);
        for(int i=0;i<v.size()-1;i++)
        reverse(s.begin()+v[i]+1,s.begin()+v[i+1]);
        reverse(s.begin()+v[v.size()-1]+1,s.end());
        return s;
    }
};
