#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1=word1.length(), len2=word2.length(),t;
        string merge;
        if(len1>=len2)
        t=len1;
        else t=len2;
        int i=0,j=0;
        while(t--)
        {
        	
            if(i<len1 && j<len2)
            {
           // 	cout<<"in1";
                merge+=word1[i];
                merge+=word2[j];
                i++; j++;
            }
            else if(i<len1)
            {
           // 	cout<<"in2";
                merge+=word1[i];
                i++;
            }
            else if(j<len2)
            {
            //	cout<<"in3";
                merge+=word2[j];
                j++;
            }
        }
        return merge;
    }
};

int main()
{
	Solution ob;
	string s1="ABCDE";
	string s2="abcdefgh";
	cout<<ob.mergeAlternately(s1,s2);
	return 0;
}


//	string str="Joy";
//	char ch=str[0];
//	str+=ch;
//	str+="h";
//	str[5]='u';
//	cout<<str;
