#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string interpret(string cmd) {
        string str;
        int len=cmd.length();
        int i=0;
        while(i<len)
        {
            if(cmd[i]=='G')
            {
                str+=cmd[i];
                i++;
            }
            else if(cmd[i]=='(' && cmd[i+1]==')')
            {
                str+='o';
                i+=2;
            }
            else if(cmd[i]=='(' && cmd[i+1]=='a' && cmd[i+2]=='l' && cmd[i+3]==')')
            {
                str+="al";
                i+=4;
            }
        }
        return str;
    }
};

int main()
{
	Solution ob;
	string s1="G()(al)";
	cout<<ob.interpret(s1);
	return 0;
}
