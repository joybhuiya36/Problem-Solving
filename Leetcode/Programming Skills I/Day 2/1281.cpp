#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int product=1, sum=0;
	while(n>0)
	{
		product*=(n%10);
		sum+=(n%10);
		n/=10;
	}
	cout<<product-sum;
	return 0;
}
