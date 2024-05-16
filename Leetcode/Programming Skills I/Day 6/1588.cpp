#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr;
	int sum=0,a;
	for(int i=0;i<8;i++)
	{
		cin>>a;
		arr.push_back(a);
	}
	for(int i=0;i<5;i++)
	cout<<arr[i]<<" ";
	for(int i=1;i<=arr.size();i+=2)
	{
		for(int j=0;j<arr.size()-(i-1);j++)
		{
			cout<<"j 2nd loop "<<j<<endl;
			for(int k=j, m=0;m<i;k++,m++)
			{
//				cout<<"k 3nd loop "<<k<<"  value "<<arr[k]<<endl;
				sum+=arr[k];
//				cout<<arr[j]<<endl;;
			}
		}
	}
	cout<<sum;
	return 0;
}


//optimized by chatgpt O(n^2)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        for (int i=0; i<arr.size(); i++) {
            for (int j=i; j<arr.size(); j++) {
                int len = j - i + 1;
                if (len & 1) {
                    for (int k=i; k<=j; k++) {
                        sum += arr[k];
                    }
                }
            }
        }
        return sum;
    }
};

//Prefix sum O(n^2)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + arr[i];
        }
        int sum = 0;
        for (int i = 1; i <= n; i += 2) {
            for (int j = 0; j < n - i + 1; j++) {
                sum += pre[j + i] - pre[j];
            }
        }
        return sum;
    }
};

