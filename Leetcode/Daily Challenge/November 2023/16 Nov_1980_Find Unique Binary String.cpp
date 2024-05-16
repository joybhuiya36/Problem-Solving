class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n =nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++)
        st.insert(stoi(nums[i],0,2));
        string num;
        for(int i=0;i<=n;i++)
        {
            if(!st.count(i))
            {
                num=bitset<16>(i).to_string();
                return num.substr(16-n,n);
            }
        }
        return "";
    }
};
//or
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n =nums.size();
        string num;
        for(int i=0;i<n;i++)
        {
            num+= nums[i][i]=='1'? '0': '1';
        }
        return num;
    }
};
