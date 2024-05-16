#include<iostream>
using namespace std;

int main()
{
	long int low, high,count=0;
	cin>>low>>high;
	if(low%2==0)
	low++;
	while(low<=high)
	{
		count++;
		low+=2;
	}
	cout<<count;
	return 0;
}
