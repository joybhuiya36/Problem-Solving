//Linear Search / Brute Force
class Solution {
public:
    char nextGreatestLetter(vector<char>& lts, char target) {
        for(char &c:lts)
        {
            if(c>target) return c;
        }
        return lts[0];
    }
};
//Binary Search
class Solution {
public:
    char nextGreatestLetter(vector<char>& lts, char target) {
        int l=0,r=lts.size()-1,mid;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if(lts[mid]>target)
            r=mid-1;
            else
            l=mid+1;
        }
        return lts.size()==l? lts[0]:lts[l];
    }
};
