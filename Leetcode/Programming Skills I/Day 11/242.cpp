#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        return false;
        vector<int> v1(26,0), v2(26,0);
        for(int i=0;i<s.length();i++)
        {
//        	cout<<s[i]-'a'<<" "<<t[i]-'a'<<endl;
            v1[s[i]-'a']++;
            v2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
//        	cout<<v1[i]<<" "<<v2[i]<<endl;
            if(v1[i]!=v2[i])
            return false;
        }
        return true;
    }
};

int main()
{
	Solution ob;
	string s="nl", t="cx";
	cout<<ob.isAnagram(s,t);
	return 0;
}
