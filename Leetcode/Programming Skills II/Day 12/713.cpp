class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& n, int k) {
        int ptr=0,count=0,mul=1;
        for(int i=0;i<n.size();i++)
        {
            if(n[i]<k)
            {
                count++;
                mul*=n[i];
                while(mul>=k)
                {
                    if(ptr<i-1)
                    count+=i-1-ptr;
                    mul/=n[ptr];
                    ptr++;
                    if(ptr==i) break;
                }
            }
            else
            {
                int ii=i-1-ptr;
                count+=(ii*(ii+1))/2;
                // while(ptr<i-1)
                // {
                //     count+=i-1-ptr;
                //     ptr++;
                // }
                mul=1;
                ptr=i+1;
            }
        }
        int i=n.size()-1-ptr;
        count+=(i*(i+1))/2;
        
        // while(ptr<i)
        // {
        //     count+=i-ptr;
        //     ptr++;
        // }
        return count;
    }
};
