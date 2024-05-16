class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int i=1, j=1;
        while(n--)
        {
            sum+=j;
            j++;
            if(j-i==7)
            {
                i++;
                j=i;
            }           
        }
        return sum;
    }
};
