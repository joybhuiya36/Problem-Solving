/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int i=0;
vector<vector<int>> v;
	void dfs(TreeNode* root)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            v[i].push_back(root->val);
        	return;
    	}
        dfs(root->left);
        dfs(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        v.push_back({});
        dfs(root1);
        i++;
        v.push_back({});
        dfs(root2);
        if(v[0].size()!=v[1].size())
        return false;
        int n=v[0].size();
        for(int i=0;i<n;i++)
        {
            if(v[0][i]!=v[1][i])
            return false;
        }
        return true;
    }
};
