class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                adj[i].push_back(leftChild[i]);
                if(mp.count(leftChild[i])) return false;
                mp[leftChild[i]]=i;
            }
            if(rightChild[i]!=-1)
            {
                adj[i].push_back(rightChild[i]);
                if(mp.count(rightChild[i])) return false;
                mp[rightChild[i]]=i;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(!mp.count(i))
            {
                if(root!=-1) return false;
                root=i;
            }
        }
        if(root==-1) return false;
        queue<int> q;
        int count=1,cur;
        q.push(root);
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            for(int i=0;i<adj[cur].size();i++)
            {
                q.push(adj[cur][i]);
                count++;
            }
        }
        return count==n;
    }
};
