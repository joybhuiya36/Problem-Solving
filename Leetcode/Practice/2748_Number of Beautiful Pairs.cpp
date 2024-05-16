//wiht extra space
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans=0,n=nums.size();
        int f[n];	//l[n]=nums[n]
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=9)
            {
                f[i]=nums[i];
            }
            else if(nums[i]<=99)
            {
                f[i]=nums[i]/10;
                nums[i]=nums[i]%10;
            }
            else if(nums[i]<=999)
            {
                f[i]=nums[i]/100;
                nums[i]=nums[i]%10;
            }
            else
            {
                f[i]=nums[i]/1000;
                nums[i]=nums[i]%10;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(gcd(f[i],nums[j])==1)
                ans++;
            }
        }
        return ans;
    }
};
//wihtout extra space
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) 
    {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {   
          int k=nums[i];
          int s=0;
          while(k!=0)
          {
              s=k%10;
              k=k/10;
          }
            for(int j=i+1;j<n;j++)
            {
                int c=__gcd(s,(nums[j]%10));
                
                if(c==1) count++;
            }
        }
       return count;
        
    }
};
