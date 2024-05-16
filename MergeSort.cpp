#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int mid,int r)
{
	int n1=mid-l+1, n2= r-mid;
	int a[n1],b[n2];
	
	for(int i=0;i<n1;i++)
	a[i]=arr[l+i];
	for(int i=0;i<n2;i++)
	b[i]=arr[mid+1+i];
	
	int i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if(a[i]<=b[j])
		{
			arr[l+k]=a[i];
			i++; k++;
		}
		else
		{
			arr[l+k]=b[j];
			j++; k++;
		}
	}
	while(i!=n1)
	{
		arr[l+k]=a[i];
		i++; k++;
	}
	while(j!=n2)
	{
		arr[l+k]=b[j];
		j++; k++;
	}
}

void mergesort(int arr[], int l, int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

int main()
{
	int arr[11]={10,1,9,2,8,3,-1,7,4,6,5};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<"Size of Array: "<<n<<endl;
	cout<<"Unsorted Array: ";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	mergesort(arr,0,n-1);
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
}
