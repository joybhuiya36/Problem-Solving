#include<bits/stdc++.h>
using namespace std;


int main()
{
//	Solution ob;
	string s="";
	string t="b";
	vector<int> ss(123,0);
	vector<int> tt(123,0);
	for(int i=0;i<t.length();i++)
	{
		ss[int(s[i])]+=1;
		tt[int(t[i])]+=1;
	}
	for(int i=0;i<t.length();i++)
	{
		if(ss[int(t[i])]!=tt[int(t[i])])
		cout<<t[i];
	}
	
	return 0;
}
//Differ of two strings character
//class Solution {
//public:
//    char findTheDifference(string s, string t) 
//    {
//      for(int i=0;i<s.size();i++)
//		t[i+1]+=t[i]-s[i]; //Passing the diff: (t[i]-s[i]) to t[i+1]
//      return t[t.size()-1]; //The diff will be carried over to the last element eventually
//    }
//};

//XOR Bit Manipulation
//    char findTheDifference(string s, string t) {
//        char ret ='\0'; // ret=0
//        for (auto &c: s) ret^=c;
//        for (auto &c: t) ret^=c;
//        return ret;
//    }
    
//class Solution {
//public:
//    char findTheDifference(string s, string t) {
//    char c;
//    vector<int> ss(123,0);
//	vector<int> tt(123,0);
//	for(int i=0;i<t.length();i++)
//	{
//		ss[int(s[i])]+=1;
//		tt[int(t[i])]+=1;
//	}
//	for(int i=0;i<t.length();i++)
//	{
//		if(ss[int(t[i])]!=tt[int(t[i])])
//		c=t[i];
//	}
//	 return c;
//    }
//};
