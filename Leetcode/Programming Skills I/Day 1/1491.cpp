#include<bits/stdc++.h>
using namespace std;

int main()
{
	double min, max,sum=0;
	vector<int> salary;
	salary.push_back(4000);
	salary.push_back(3000);
	salary.push_back(1000);
	salary.push_back(2000);
	sort(salary.begin(),salary.end());
	for(int i=1;i<salary.size()-1;i++)
	sum+=salary[i];
	cout<<sum/(salary.size()-2);
	return 0;
	}
	
	//[48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000]
