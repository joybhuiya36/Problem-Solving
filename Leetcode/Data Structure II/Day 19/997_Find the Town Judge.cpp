//My Solution
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size()==0) return 1;
        unordered_map<int,int> mp;
        unordered_set<int> notAdd;
        for(int i=0;i<trust.size();i++)
        {
            notAdd.insert(trust[i][0]);
            if(!notAdd.count(trust[i][1]))
            mp[trust[i][1]]++;
            if(mp.count(trust[i][0]))
            {
                mp.erase(trust[i][0]);
                notAdd.insert(trust[i][0]);
            }
        }
        if(mp.size()==0) return -1;
        auto it=mp.begin();
        if(it->second==n-1 && mp.size()==1)
        return it->first;
        else return -1;
    }
};
//indegree and outdegree process
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Another approch could be that for a person to be a judge indegree-outdegree=n-1
        // so for outgoing edge do -1 and for incoming edge add +1
        vector<int> v(n,0);
        for(int i=0;i<trust.size();i++){
            v[trust[i][0]-1]--;
            v[trust[i][1]-1]++;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==n-1){
                return i+1;
            }
        }
        return -1;
    }
};
