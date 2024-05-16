class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0, i=0;
        if(flowerbed.size()==1)
        {
            if(flowerbed[0]==0)
            count++;
            return count>=n;
        }
        if(flowerbed[i]==0 && flowerbed[i+1]==0)
        {
            flowerbed[i]=1;
            count++;
        }
        i++;
        for(;i<flowerbed.size()-1;i++)
        {
            if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                count++;
            }
        }
        if(flowerbed[i]==0 && flowerbed[i-1]==0)
        count++;
        return count>=n;
    }
};
