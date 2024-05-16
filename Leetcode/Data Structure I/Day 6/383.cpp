#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26,0);
        for(int i=0;i<magazine.length();i++)
        {
            v[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.length();i++)
        {
            v[ransomNote[i]-'a']--;
            if(v[ransomNote[i]-'a']==-1)
            return false;
        }
        return true;
    }
};

int main()
{
	Solution ob;
	string r="aa", m="aab";
	cout<<ob.canConstruct(r,m);
	return 0;
}
