class Solution {
public:
    bool func(ListNode* head, TreeNode* root)
    {
        if(head->next==NULL)
        return true;
        bool ll,rr;
        if(root->left!=NULL && head->next->val==root->left->val)
        ll=func(head->next,root->left);
        if(root->right!=NULL && head->next->val==root->right->val)
        rr=func(head->next,root->right);
        return ll || rr;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q,stk;
        q.push(root);
        TreeNode* cur;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                cur=q.front();
                if(cur->val==head->val)
                stk.push(cur);
                q.pop();
                if(cur->left)
                q.push(cur->left);
                if(cur->right)
                q.push(cur->right);
            }
        }
        while(!stk.empty())
        {
            root=stk.front();
            bool ch=func(head,root);
            if(ch==true) return true;
            stk.pop();
        }
        return false;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
