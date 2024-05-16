class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(root->left) {
            //find right most guy in the left sub tree
            TreeNode* temp = root->left;
            while(temp->right) temp = temp->right;
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        } 
        flatten(root->right);
    }
};
//or
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* cur;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            cur=stk.top();
            stk.pop();

            if(cur->right!=NULL)
            stk.push(cur->right);
            if(cur->left!=NULL)
            stk.push(cur->left);

            root->left=NULL;
            root->right=cur;
            root=root->right;
        }
        root->left=NULL;
        root->right=NULL;
        root=root->right;
    }
};
