#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<vector<int> > v(26,(vector<int>(2,0)));
        int mn=999999;
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a'][0]++;
            v[s[i]-'a'][1]=i;
        }
        for(int i=0;i<26;i++)
        {
            if(v[i][0]==1 && v[i][1]<mn)
            {
                mn=v[i][1];
            }
           // cout<<"index "<<i<<" "<<char(i+'a')<<" "<<v[i]<<endl;
        }
        if(mn==999999)
        return -1;
        else return mn;
    }
};

int main()
{
	Solution ob;
	string s="aabb";
	cout<<ob.firstUniqChar(s);
	return 0;
}
