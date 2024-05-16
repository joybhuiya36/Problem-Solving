class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=-1, r=-1;
        if(left.size()>0)
        l=*max_element(left.begin(),left.end());
        if(right.size()>0)
        r=*min_element(right.begin(),right.end());
        if(l!=-1 && r!=-1)
        return max(l,n-r);
        if(l!=-1)
        return l;
        return n-r;
    }
};
