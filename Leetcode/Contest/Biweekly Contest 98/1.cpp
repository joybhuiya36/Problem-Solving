#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> v;
        int count=0,count2=0,n=num,k=1,f_dgt;
        while(n)
        {
            v.push_back(n%10);
            count++;
            n/=10;
            k*=10;
        }
        k/=10;
        for(int i=v.size()-1;i>=0;i--)
        {
        	if(v[i]!=9)
        	{
			f_dgt=i;
			break;
			}
			count2++;
		}
        if(count==count2)
        return num;
        int s1=0,s2=0;
        for(int i=v.size()-1;i>=0;i--)
        {
        	if(v[f_dgt]==v[i])
        	s1+=9*k;
			else
			s1+=v[i]*k;
			
			if(v[v.size()-1]==v[i])
        	s2+=0*k;
			else
        	s2+=v[i]*k;
        	k/=10;
		}
        return s1-s2;
    }
};

int main()
{
	int a=99999;
	Solution ob;
	cout<<ob.minMaxDifference(a);
	return 0;
}
