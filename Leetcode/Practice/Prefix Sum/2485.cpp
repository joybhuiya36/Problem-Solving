#include<bits/stdc++.h>
using namespace std;
//sum=n(n+1)/2 formula
int main()
{
	int n;
	cin>>n;
	int x=-1, i=n/2;
	int n_sum=(n*(n+1))/2;
	int i_sum=((i-1)*i)/2;;
	//cout<<n_sum<<" "<<i_sum<<endl;
	
	for(;i<=n;i++)
	{
		i_sum+=i;
	//	cout<<i_sum<<" "<<n_sum-i_sum+i<<endl;
		if(i_sum==n_sum-i_sum+i)
		x=i;
	}
	cout<<x;
//    cout<<n<<" "<<pre[n];
    return 0;
}

//Prefix Sum Formula
//class Solution {
//public:
//    int pivotInteger(int n) {
//    int x=-1;
//	vector<int> pre(n+1,0);
//    for(int i=0;i<n;i++)
//    {
//        pre[i+1]=i+1+pre[i];
//    }
//    for(int i=n;i>0;--i)
//    {
//    	if((pre[n]-pre[i-1])==pre[i])
//    	{
//    		x=i;
//		}
//	}
//    return x;
//    }
//};
