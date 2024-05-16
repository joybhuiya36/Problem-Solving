//Array
class Solution {
public:
    vector<int> partitionLabels(string &s) {
        int mp[26]={0};
        vector<int>v;
        int n=s.size(), ptr=0, l=-1;
        for(int i=0;i<n;i++)
        mp[s[i]-'a']=i;
        for(int i=0;i<n;i++)
        {
            ptr=max(ptr,mp[s[i]-'a']);
            if(i==ptr)
            {
                v.push_back(ptr-l);
                l=ptr;
            }
        }
        return v;
    }
};
//Unordered_Map
class Solution {
public:
    vector<int> partitionLabels(string &s) {
        unordered_map<char,int> mp;
        vector<int>v;
        int n=s.size(), ptr=0, l=-1;
        for(int i=0;i<n;i++)
        mp[s[i]]=i;
        for(int i=0;i<n;i++)
        {
            ptr=max(ptr,mp[s[i]]);
            if(i==ptr)
            {
                v.push_back(ptr-l);
                l=ptr;
                ptr=0;
            }
        }
        return v;
    }
};
