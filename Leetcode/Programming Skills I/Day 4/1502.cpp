#include<bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}


class Solution {
public:
    int arraySign(vector<int>& nums) {
        int flag=0, count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            count++;
            else if(nums[i]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        return 0;
        else if(count%2==0)
        return 1;
        else
        return -1;
    }
};
