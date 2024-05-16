class NumArray {
vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        arr.push_back(0);
        for(int i=1;i<=nums.size();i++)
        arr.push_back(arr[i-1]+nums[i-1]);
    }
    
    int sumRange(int left, int right) {
        return arr[right+1]-arr[left];
    }
};
//https://leetcode.com/study-plan/programming-skills/?progress=x8ynjf6r
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
