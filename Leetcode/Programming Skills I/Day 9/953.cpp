#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> ind(26);
	
	vector<string> words;
	words.push_back("hello");
	words.push_back("leetcode"); //["word","world","row"]
	words.push_back("hello");
	string order="hlabcdefgijkmnopqrstuvwxyz";
	
	for(int i=0;i<order.length();i++)
	ind[order[i]-'a']=i;
	
	int flag,flag2,flag3;
	for(int i=0;i<words.size()-1;i++)
	{
		int n=words[i].size();
		int m=words[i+1].size();
		int t;
		flag=1;
		n<m ? t=n : t=m;
		for(int j=0;j<t;j++)
		{
			cout<<words[i][j]<<" "<<words[i+1][j]<<endl;
			flag2=0;
			if(ind[words[i][j]-'a'] < ind[words[i+1][j]-'a'])
			{
				break;
			}
			else if(ind[words[i][j]-'a'] == ind[words[i+1][j]-'a'])
			{
				flag2=1;
				continue;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==0) break;
		if(n>m && flag2==1)
		{
			int flag3=1;
			cout<<"Nooo"<<endl;
			break;
		}
	}
	if(flag==1 && flag3!=1)
	cout<<"Yes"<<endl;
	else if(flag==0)
	cout<<"No"<<endl;
	return 0;
}

//0ms
//class Solution {
//public:
//        bool isAlienSorted(vector<string> words, string order) {
//        int mapping[26];
//        for (int i = 0; i < 26; i++)
//            mapping[order[i] - 'a'] = i;
//        for (string &w : words)
//            for (char &c : w)
//                c = mapping[c - 'a'];
//        return is_sorted(words.begin(), words.end());
//    }
//};

//my 5ms
//class Solution {
//public:
//    bool isAlienSorted(vector<string>& words, string order) {
//	int flag;
//    vector<int> ind(26);
//	for(int i=0;i<order.length();i++)
//	ind[order[i]-'a']=i;
//	for(int i=0;i<words.size()-1;i++)
//	{
//		int n=words[i].size();
//		int m=words[i+1].size();
//		int t;
//		flag=1;
//		n<m ? t=n : t=m;
//		for(int j=0;j<t;j++)
//		{
//			flag=0;
//			if(ind[words[i][j]-'a'] < ind[words[i+1][j]-'a'])
//			break;
//			else if(ind[words[i][j]-'a'] == ind[words[i+1][j]-'a'])
//			{
//				flag=1;
//				continue;
//			}
//			else
//			return false;
//		}
//		if(n>m && flag==1)
//		return false;
//	}
//	return true;
//    }
//};
