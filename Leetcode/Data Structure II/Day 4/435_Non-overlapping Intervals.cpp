//Sorted through end time
//[[1,5],[1,8],[2,3],[3,5],[5,8]]
//2 3 
//3 5 
//1 5 
//5 8 
//1 8 
class Solution 
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[1]==b[1])
        return a[0]>b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>&v) 
    {
        sort(v.begin(),v.end(),cmp);
        // for(auto &i:v)
        // {
        //     for(auto& j:i)
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
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
//Ascending Sort
// Case 1:-
// ------------------   -----------------
// |   Interval 1   |   |   Interval 2  |
// ------------------   -----------------

//Case 2:-
// ------------------
// |   Interval 1   |
// ------------------
//            ------------------
//            |    Interval 2  |
//            ------------------

//Case 3:-
//  --------------------
//  |    Interval 1    |
//  --------------------
//     --------------
//     | Interval 2 |
//     --------------
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>&v) 
    {
        sort(v.begin(),v.end());
        int rmv=0,l=0,r=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[l][1]<=v[r][0])	// Non-overlapping case(Case 1)
            {
                l=r;
                r++;
            }
            else if(v[l][1]<=v[r][1])	// Case 2
            {
                rmv++;
                r++;
            }
            else if(v[l][1]>v[r][1])	// Case 3
            {
                rmv++;
                l=r;
                r++;
            }
        }
        return rmv;
    }
};
//Another Logic
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), ans = 0;
        for (int i = 1; i < n; ++i) {
            if (intervals[i-1][1] > intervals[i][0]) {
                ++ans;
                intervals[i][1] = min(intervals[i-1][1], intervals[i][1]);
            }
        }
        return ans;
    }
};
