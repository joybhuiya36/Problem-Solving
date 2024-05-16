#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        int i=m-1, j=n-1, k=m+n-1;
        while(j>=0 && i>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0)
        {
            nums1[k]=nums2[j];
            j--; k--;
        }
    }
};

int main()
{
	vector<int> n1,n2;
	n1.push_back(2);
	n1.push_back(4);
	n1.push_back(6);
	
	n2.push_back(1);
	n2.push_back(2);
	n2.push_back(2);
	n2.push_back(3);
	n2.push_back(8);
	//n1.resize(n1.size()+n2.size());
	for(int i=0;i<n1.size();i++)
	cout<<n1[i]<<" ";
	cout<<endl;
	for(int i=0;i<n2.size();i++)
	cout<<n2[i]<<" ";
	cout<<endl;
	Solution ob;
	ob.merge(n1,n1.size(),n2,n2.size());
	for(int i=0;i<n1.size();i++)
	cout<<n1[i]<<" ";
	return 0;
}



//class Solution {
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        nums1.resize(m+n);
//        int k=m;
//        for(int i=0,j=0;i<m+n-1;)
//        {
//        	//cout<<i<<" ";
//            if(i<m && j<n)
//            {
//            	cout<<"n1 "<<nums1[i]<<" n2 "<<nums2[j]<<endl;
//                if(nums1[i]<=nums2[j])
//	            {
//	                i++;
//	            }
//	            else
//	            {
//	                swap(nums1[i],nums2[j]);
//	                i++;
//	                if(j<n-1)
//	                {
//	                    if(nums2[j]>nums2[j+1])
//	                    {
//	                        nums1[k]=nums2[j];
//	                        j++; k++;
//	                    }
//	                    
//	                }
//	                else if(j==n-1)
//	                {
//	                    nums1[k]=nums2[j];
//	                    k++; j++;
//	                }
//	                
//	            }
//            }
//            else if(j<n)
//            {
//            	while(j<n)
//            	{
//            		nums1[i]=nums2[j];
//            		i++; j++;
//				}
//			}
//            else
//            {
//                if(nums1[i+1]<nums1[i])
//                {
//                	swap(nums1[i+1],nums1[i]);
//                	i++;
//				}
//            }
//        }
//    }
//};
