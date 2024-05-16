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
        TreeNode* ll1;
        TreeNode* ll2;
        TreeNode* rr1;
        TreeNode* rr2;
        int sum;

        TreeNode* func(TreeNode* r1, TreeNode* r2)
        {
            cout<<"recur"<<endl;
            sum=0;
            if(r1==NULL && r2==NULL)
            {
                cout<<"both null"<<endl;
                return NULL;
            }

            if(r1==NULL)
            ll1=NULL;
            else ll1=r1->left;
            if(r2==NULL)
            ll2=NULL;
            else ll2=r2->left;

            if(r1==NULL)
            rr1=NULL;
            else rr1=r1->right;
            if(r2==NULL)
            rr2=NULL;
            else rr2=r2->right;
            
            if(r1!=NULL)
            sum+=r1->val;
            if(r2!=NULL)
            sum+=r2->val;
            TreeNode* root= new TreeNode(sum);
            cout<<"sum "<<sum<<endl;
            root->left= mergeTrees(ll1, ll2);
            root->right=mergeTrees(rr1, rr2);
            return root;
        }
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        return func(r1,r2);
    }
};
