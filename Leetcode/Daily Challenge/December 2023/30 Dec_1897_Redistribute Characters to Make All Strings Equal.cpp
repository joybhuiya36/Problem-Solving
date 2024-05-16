class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        int arr[26]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                arr[words[i][j]-'a']++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]%n!=0)
            return false;
        }
        return true;
    }
};
