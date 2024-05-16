class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int startEnd[n+1];
        int start,end;
        memset(startEnd,0,sizeof(startEnd));
        for(int i=0;i<=n;i++)
        {
            start=max(i-ranges[i],0);
            end=min(i+ranges[i],n);
            startEnd[start]=max(startEnd[start],end);
        }
        int tap=0,curEnd=0,maxEnd=0;
        for(int i=0;i<=n;i++)
        {
            if(i>maxEnd)
            return -1;
            if(i>curEnd)
            {
                tap++;
                curEnd=maxEnd;
            }
            maxEnd=max(maxEnd,startEnd[i]);
        }
        return tap;
    }
};
