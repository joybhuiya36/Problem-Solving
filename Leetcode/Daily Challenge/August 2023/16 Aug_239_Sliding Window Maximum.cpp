class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0,n=nums.size(),ptr=0;
        while(i<k)
        {
            while(!dq.empty() && nums[i]>dq.back())
            dq.pop_back();
            dq.push_back(nums[i]);
            i++;
        }
        vector<int> v;
        v.push_back(dq.front());
        while(i<n)
        {
            if(dq.front()==nums[ptr])
            dq.pop_front();

            while(!dq.empty() && nums[i]>dq.back())
            dq.pop_back();
            dq.push_back(nums[i]);
            i++;
            ptr++;
            v.push_back(dq.front());
        }
        return v;
    }
};
