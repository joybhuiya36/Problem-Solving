//BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        int n;
        while(!q.empty())
        {
            v.push_back(q.front()->val);
            n=q.size();
            while(n--)
            {
                root=q.front();
                q.pop();
                if(root->right)
                q.push(root->right);
                if(root->left)
                q.push(root->left);
            }
        }
        return v;
    }
};
//DFS
class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans, int lvl){
        // base case
        if(root==NULL){
            return;
        }
        
        // entered a new level
        if(lvl==ans.size()){
            ans.push_back(root->val);
        }
        
        // since we need right view toh root->right pehle call hoga and left wla call hota
        // agar left view poocha hota toh;
        solve(root->right, ans, lvl+1);
        solve(root->left, ans, lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};
