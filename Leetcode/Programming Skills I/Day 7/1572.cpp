#include<bits/stdc++.h>
using namespace std;

int main()
{
	int mat[4][4];
	freopen("input.txt","r",stdin);
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	cin>>mat[i][j];
//	for(int i=0;i<4;i++)
//	for(int j=0;j<4;j++)
//	cout<<mat[i][j]<<" \t\t";
	
	int sum=0,n=4;
        for(int i=0;i<n;i++)
        {
            sum+=mat[i][i];
            if(i<n/2)
            {
            sum+=mat[i][n-i-1]+mat[n-i-1][i];
//            cout<<mat[i][n-i-1]<<" "<<mat[n-i-1][i]<<endl;
			}
        }
        cout<<sum;
	return 0;
}


//class Solution {
//public:
//    int diagonalSum(vector<vector<int>>& mat) {
//        int sum=0,n=mat.size();
//        for(int i=0;i<n;i++)
//        sum+=mat[i][i];
//        for(int i=0;i<n/2;i++)
//        sum+=mat[i][n-1]+mat[n-1][i];
//        return sum;
//    }
//};

//class Solution {
//public:
//    int diagonalSum(vector<vector<int>>& mat) {
//        int sum=0,n=mat.size();
//        for(int i=0;i<n/2;i++)
//        sum+=mat[i][i]+mat[n-i-1][n-i-1]+mat[i][n-i-1]+mat[n-i-1][i];
//        if(n%2==1)
//        sum+=mat[(n/2)][(n/2)];
//        return sum;
//    }
//};
