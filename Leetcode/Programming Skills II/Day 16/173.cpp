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
class BSTIterator {
public:
    vector<int> v;
    stack<TreeNode*> stk;
    int i=-1;
    BSTIterator(TreeNode* root) {
        TreeNode* cur=root;
        while(cur || !stk.empty())
        {
            while(cur)
            {
                stk.push(cur);
                cur=cur->left;
            }
            cur=stk.top();
            stk.pop();
            v.push_back(cur->val);
            // cout<<cur->val<<" ";
            cur=cur->right;
        }
    }
    
    int next() {
        return v[++i];
    }
    
    bool hasNext() {
        if(i+1<v.size())
        return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
