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
 //DFS Recursive
class Solution {
public:
    bool func(TreeNode* L, TreeNode* R)
    {
        if(L==NULL && R==NULL)
        return true;
        else if(L==NULL || R==NULL)
        return false;
        if(L->val!=R->val)
        return false;
        bool rslt1=func(L->left, R->right);
        bool rslt2=func(L->right, R->left);
        return rslt1 && rslt2;
    }
    bool isSymmetric(TreeNode* root) {
        return func(root->left, root->right);
    }
};
 //BFS Iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1,q2;

        if((root->left==NULL || root->right==NULL) && (root->left!=root->right))
            return false;
        else if(root->left==NULL && root->right==NULL)
        return true;
        else if((root->left->val==root->right->val))
        {
            q1.push(root->left);
            q2.push(root->right);
        }
        else return false;
        
        while(!q1.empty() || !q2.empty())
        {
            TreeNode* tm1=q1.front();
            TreeNode* tm2=q2.front();
            q1.pop();
            q2.pop();
            if( ((tm1->left==NULL || tm2->right==NULL) && (tm1->left!=tm2->right)) )
            return false;
            else if(tm1->left==NULL && tm2->right==NULL)
            goto nxt;
            else if(tm1->left->val==tm2->right->val)
            {
                if(tm1->left)
                q1.push(tm1->left);
                if(tm2->right)
                q2.push(tm2->right);
            }
            else return false;

            nxt:
            if( ((tm2->left==NULL || tm1->right==NULL) && (tm2->left!=tm1->right)) )
            return false;
            else if(tm2->left==NULL && tm1->right==NULL)
            continue;
            else if(tm2->left->val==tm1->right->val)
            {
                if(tm1->right)
                q1.push(tm1->right);
                if(tm2->left)
                q2.push(tm2->left);
            }
            else return false;
        }
        return true;
    }
};
