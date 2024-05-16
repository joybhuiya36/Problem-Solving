//Recursion
class Solution {
public:
    vector<int> inorder;
    void traversal(TreeNode* root){
        if(root==NULL) return;
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
        return;
    }
};
//Iternation
class Solution {
public:
    vector<int> inorder;
    void traversal(TreeNode* root){
        stack<TreeNode*> stk;
        vector<int> v;
        while(cur || !stk.empty())
        {
            while(cur)
            {
                stk.emplace(cur);
                cur=cur->left;
            }
            cur=stk.top();
            stk.pop();
            v.push_back(cur->val);
            cur=cur->right;
        }
        for(auto &i:v)
        cout<<i<<" ";
    }
};
