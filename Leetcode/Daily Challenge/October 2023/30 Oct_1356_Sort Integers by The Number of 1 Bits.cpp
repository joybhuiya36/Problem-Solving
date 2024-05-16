class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
    	int count=0,n;
        vector<vector<int> > v(14);
        sort(arr.begin(),arr.end());
	    for(int i=0;i<arr.size();i++)
	    {
	    	count=0;
	    	n=arr[i];
	    	while(n)
	    	{
	    		n&=n-1;
	    		count++;
			}
			v[count].push_back(arr[i]);
		}
		int k=0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i].size()!=0)
			{
				for(int j=0;j<v[i].size();j++)
				{
					arr[k]=v[i][j];
					k++;
				}
			}
		}
		return arr;
    }
};
