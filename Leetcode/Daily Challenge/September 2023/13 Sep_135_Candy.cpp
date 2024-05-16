class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int candy=n;
        int i=1,peak,dig;
        while(i<n)
        {
            if(ratings[i-1]==ratings[i])
            {
                i++;
                continue;
            }
            peak=0;
            while(ratings[i-1]<ratings[i])
            {
                peak++;
                candy+=peak;
                i++;
                if(i==n) return candy;
            }
            dig=0;
            while(i<n && ratings[i-1]>ratings[i])
            {
                dig++;
                candy+=dig;
                i++;
            }
            candy-=min(peak,dig);
        }
        return candy;
    }
};
