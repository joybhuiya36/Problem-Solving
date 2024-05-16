class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1);
        v[0]=1;
        int n;
        for(int i=1;i<=rowIndex;i++)
        {
            n=i/2;
            while(n)
            {
                v[n]=v[n]+v[n-1];
                n--;
            }
            if(i%2==1)
            v[(i/2)+1]=v[i/2];
        }
        int i=(rowIndex/2)+1;
        int j;
        if(rowIndex%2==1)
        j=rowIndex/2;
        else
        j=(rowIndex/2)-1;
        while(i<=rowIndex)
        v[i++]=v[j--];
        return v;
    }
};
