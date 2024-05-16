class Solution {
public:
    int poorPigs(int buckets, int minToDie, int minToTest) {
        int t=minToTest/minToDie+1;
        int pigs=0;
        while(pow(t,pigs)<buckets)
        pigs++;
        return pigs;
    }
};
