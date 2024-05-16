class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int mx=nums[0];
        long long sum=mx;
        double avg;
        for(int i=1; i<nums.size();i++)
        {
            sum+=nums[i];
            avg=1.0*sum/(i+1);
            mx=max(mx,int(ceil(avg)));
        }
        return mx;
    }
};
//Or
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int mx=nums[0];
        long long sum=mx;
        for(int i=1; i<nums.size();i++)
        {
            sum+=nums[i];
            mx=max(mx,(sum+i)/(i+1));	//Ceiling
        }
        return mx;
    }
};
//Or
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int mx=nums[0];
        long long sum=mx;
        double avg;
        for(int i=1; i<nums.size();i++)
        {
            sum+=nums[i];
            avg=(1.0*sum)/(i+1);
            if(avg!=int(avg))		//Ceiling
            avg=int(avg)+1;
            mx=max(mx,int(avg));
        }
        return mx;
    }
};
