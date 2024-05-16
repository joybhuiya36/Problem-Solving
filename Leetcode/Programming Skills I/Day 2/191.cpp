#include<iostream>
#include<bitset>
using namespace std;

int main()
{
	unsigned int n, count=0;
	cin>>n;
	string s= bitset<32>(n).to_string();
	cout<<s<<endl;
	for(int i=0;s[i]!='\0';i++)
	if(s[i]=='1')
	count++;
	cout<<count;
	return 0;
}

//class Solution {
//public:
//    int hammingWeight(uint32_t n) {
//        int count=0;
//	    while(n!=0)
//        {
//            if(n%2==1)
//            count++;
//            n/=2;
//        }
//	return count;
//    }
//};
