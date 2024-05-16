//Sorted according to End time
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>&v) 
    {
        auto cmp=[&](vector<int> &a, vector<int> &b)
        {
            return a[1]<b[1];
        };
        sort(v.begin(),v.end(),cmp);

        int rmv=0,end=v[0][1];
        for(int i=1;i<v.size();i++)
        {
            if(v[i][0]<end)
            rmv++;
            else end=v[i][1];
        }
        return rmv;
    }
};
//Sorted according to Start time
//Always act as greedy, take the short end
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>&v) 
    {
        sort(v.begin(),v.end());
        int rmv=0,l=0,r=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[l][1]<=v[r][0])
            {
                l=r;
                r++;
            }
            else if(v[l][1]<=v[r][1])
            {
                rmv++;
                r++;
            }
            else if(v[l][1]>v[r][1])
            {
                rmv++;
                l=r;
                r++;
            }
        }
        return rmv;
    }
};
