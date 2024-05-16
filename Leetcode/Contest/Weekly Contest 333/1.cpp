#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector< vector<int> > mergeArrays(vector< vector<int> >& nums1, vector< vector<int> >& nums2) {
        int n1=nums1.size(), n2=nums2.size(),i=0,j=0,k=0;
		vector< vector<int> > v((n1+n2), vector<int>(2));
        
        while(i<n1 && j<n2)
        {
            if(nums1[i][0]==nums2[j][0])
            {
                v[k][0]=nums1[i][0];
                v[k][1]=nums1[i][1]+nums2[j][1];
                i++; j++; k++;
            }
            else if(nums1[i][0]>nums2[j][0])
            {
                v[k][0]=nums2[j][0];
                v[k][1]=nums2[j][1];
                j++; k++;                   
            }
            else
            {
                v[k][0]=nums1[i][0];
                v[k][1]=nums1[i][1];
                i++; k++;
            }
        }
        while(i<n1)
        {
            v[k][0]=nums1[i][0];
            v[k][1]=nums1[i][1];
            i++; k++;
        }
        while(j<n2)
        {
           v[k][0]=nums2[j][0];
            v[k][1]=nums2[j][1];
            j++; k++; 
        }
        v.resize(k+2,vector<int>(2));
	    for(int i=0;i<v.size();i++)
		{
		for(int j=0;j<v[i].size();j++)
		cout<<v[i][j]<<" ";
		cout<<endl;
		}
        return v;
    }
};

int main()
{
	vector< vector<int> > v1(3, vector<int> (2)), v2(3, vector<int> (2));	//[[1,2],[2,3],[4,5]]	[[1,4],[3,2],[4,1]]
	v1[0][0]=1;
	v1[0][1]=2;
	v1[1][0]=2;
	v1[1][1]=3;
	v1[2][0]=4;
	v1[2][1]=5;
	
	v2[0][0]=1;
	v2[0][1]=4;
	v2[1][0]=3;
	v2[1][1]=2;
	v2[2][0]=4;
	v2[2][1]=1;
//	for(int i=0;i<v1.size();i++)
//	{
//	for(int j=0;j<v1[i].size();j++)
//	cout<<v1[i][j]<<" ";
//	cout<<endl;
//	}
//	for(int i=0;i<v2.size();i++)
//	{
//	for(int j=0;j<v2[i].size();j++)
//	cout<<v2[i][j]<<" ";
//	cout<<endl;
//	}
	Solution ob;
	ob.mergeArrays(v1,v2);
	return 0;
}
