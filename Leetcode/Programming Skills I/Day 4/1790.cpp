#include<bits/stdc++.h>
using namespace std;

int main()
{
	int ch[3];
	int count=0,flag=0;
	string s1,s2;
	cin>>s1>>s2;
	if(s1==s2)
	goto rt;
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]!=s2[i])
		{
			ch[count]=i;
			count++;
		}
		if(count>2)
		{
			flag=1;
			break;
		}
	}
//	cout<<count<<endl;
//	cout<<ch[0]<<" "<<ch[1]<<endl;
	swap(s2[ch[0]],s2[ch[1]]);
	rt:
	if(count<3&&s1==s2&&flag==0)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
    return 0;
}


//class Solution {
//public:
//    bool areAlmostEqual(string s1, string s2) {
//	int ch[3];
//	int count=0,flag=0;
//    if(s1==s2)
//    return true;
//	for(int i=0;i<s1.length();i++)
//	{
//		if(s1[i]!=s2[i])
//		{
//			ch[count]=i;
//			count++;
//		}
//		if(count>2)
//		{
//			flag=1;
//			break;
//		}
//	}
//	swap(s2[ch[0]],s2[ch[1]]);
//	if(count<3&&s1==s2&&flag==0)
//    return true;
//	else
//	return false;
//    }
//};


//class Solution {
//public:
//    bool areAlmostEqual(string s1, string s2) {
//    vector<int> ch;
//	int count=0,flag=0;
//	for(int i=0;i<s1.length();i++)
//	{
//		if(s1[i]!=s2[i])
//		{
//			ch.push_back(i);
//			count++;
//		}
//	}
//    if(count==s1.length()||count%2==1)
//	goto rt;
//	
//	for(int i=0;i<ch.size();i++)
//	{
//		for(int j=0;j<ch.size();j++)
//		{
//			if(s1[ch[i]]==s2[ch[j]])
//			{
//	
//				s2[ch[j]]=s2[ch[i]];
//				s2[ch[i]]=s1[ch[i]];
//				count--;
//				if(s1[ch[j]]==s2[ch[j]])
//				count--;
//			}
//			if(count==0)
//			{
//				flag=1;
//				break;
//			}
//		}
//		if(flag==1)
//		break;
//	}
//    rt:
//	if(count==0)
//    return true;
//	else
//	return false;
//    }
//};

